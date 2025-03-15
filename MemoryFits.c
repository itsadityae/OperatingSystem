#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int n1,n2;
	printf("Enter No. available block in Memory : ");
	scanf("%d" ,&n1);
	int S1[2][n1];
	printf("Enter Sequence of available size in Memory block(MB) (one by one): ");
	for (int i=0; i<n1; i++)
	{
		scanf("%d" ,&S1[0][i]);
		S1[1][i] = 0;
	}

	printf("Enter No. requested memory block : ");
	scanf("%d" ,&n2);
	int S2[n2],S3[n2];
	printf("Enter the Sequence of requested size of memory block(MB) : ");
	for (int i=0; i<n2; i++)
	{
		scanf("%d" ,&S2[i]);
		S3[i] = -1;
	}

	int ch;
	printf("\n\t1.First Fit\n\t2.Next Fit\n\t3.Best Fit\nChoose the Algorithm No. : ");
	scanf("%d",&ch);

	int last,Best,idx;
	last = 0;
	switch (ch) 
	{
		case 1 :
			for (int i = 0; i < n2; i++)
			{
				for (int j=0 ; j < n1 ; j++)
				{
					if (S2[i] <= S1[0][j] && S1[1][j] == 0)
					{
						S3[i] = S1[0][j];
						S1[1][j] = 1;
						break;  
					}
				}
			}

		case 2 :
			for (int i = 0; i < n2; i++)
			{	
				for (int j=last ; j < n1 ; j++)
				{
					if (S2[i] <= S1[0][j] && S1[1][j] == 0)
					{
						S3[i] = S1[0][j];
						S1[1][j] = 1;
						last = j;
						break;  
					}
				}
			}

		case 3 :
			for (int i = 0; i < n2; i++)
			{
				Best = 100000;
				for (int j=0 ; j < n1 ; j++)
				{
					if (S2[i] <= S1[0][j] && S1[1][j] == 0 && S1[0][j] < Best )
					{
						Best = S1[0][j];
						idx = j ;
					}
				}
				if (Best != 100000)
				{
				S3[i] = S1[0][idx];
				S1[1][idx] = 1;
				} 
			}
	}	
	
	printf("Request No.\tSize of Block(MB)\tAllocated Block size(MB)\n");
	for(int i = 0 ; i < n2 ; i++)
	{
		if (S3[i] == -1)
		{

			printf("B%d\t\t%d\t\t\tNo Block allocated\n",i+1,S2[i]);
		}
		else
		{

			printf("B%d\t\t%d\t\t\t%d\n",i+1,S2[i],S3[i]);
		}
	} 
	return 0;
}
