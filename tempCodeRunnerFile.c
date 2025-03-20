#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define TIMEOUT 3

void sendPacket(int packet)
{
    printf("Sending packet %d...\n", packet);
    sleep(1);
}

bool receiveAck()
{
    return rand() % 10 < 8;
}

int main()
{
    srand(time(NULL));

    int packetsToSend = 5;
    int sentPackets = 0;

    printf("Sender: Initiating transmission of %d packets.\n", packetsToSend);

    while (sentPackets < packetsToSend)
    {
        sendPacket(sentPackets);

        time_t startTime = time(NULL);
        printf("Sender: Waiting for acknowledgment for packet %d...\n", sentPackets);
        while (true)
        {
            if (difftime(time(NULL), startTime) >= TIMEOUT)
            {
                printf("Sender: Timeout occurred while waiting for acknowledgment for packet %d.\n", sentPackets);
                break;
            }

            if (receiveAck())
            {
                printf("Sender: Acknowledgment received for packet %d.\n", sentPackets);
                sentPackets++;
                break;
            }
        }
    }

    printf("Sender: All packets sent successfully.\n");

    return 0;
}
