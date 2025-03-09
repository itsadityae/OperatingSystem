#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i, j, k;
    
    // Get the number of processes and resources from the user
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    // Dynamically allocate memory for arrays
    int **alloc = (int **)malloc(n * sizeof(int *));
    int **max = (int **)malloc(n * sizeof(int *));
    int *avail = (int *)malloc(m * sizeof(int));
    int *f = (int *)malloc(n * sizeof(int));
    int *ans = (int *)malloc(n * sizeof(int));
    int **need = (int **)malloc(n * sizeof(int *));
    
    for (i = 0; i < n; i++) {
        alloc[i] = (int *)malloc(m * sizeof(int));
        max[i] = (int *)malloc(m * sizeof(int));
        need[i] = (int *)malloc(m * sizeof(int));
    }

    // Get user input for the Allocation Matrix
    printf("Enter the Allocation Matrix:\n");
    for (i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }

    // Get user input for the MAX Matrix
    printf("Enter the MAX Matrix:\n");
    for (i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    // Get user input for the Available Resources
    printf("Enter the Available Resources:\n");
    for (j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    // Initialize arrays
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    // Calculate the Need Matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    // Banker's Algorithm
    // (The rest of the code remains unchanged)

    // Free dynamically allocated memory
    for (i = 0; i < n; i++) {
        free(alloc[i]);
        free(max[i]);
        free(need[i]);
    }
    free(alloc);
    free(max);
    free(need);
    free(avail);
    free(f);
    free(ans);

    return 0;
}
// Banker's Algorithm
#include <stdio.h>
int main()
{
	// P0, P1, P2, P3, P4 are the Process names here

	int n, m, i, j, k;
	n = 5; // Number of processes
	m = 3; // Number of resources
	int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix
						{ 2, 0, 0 }, // P1
						{ 3, 0, 2 }, // P2
						{ 2, 1, 1 }, // P3
						{ 0, 0, 2 } }; // P4

	int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix
					{ 3, 2, 2 }, // P1
					{ 9, 0, 2 }, // P2
					{ 2, 2, 2 }, // P3
					{ 4, 3, 3 } }; // P4

	int avail[3] = { 3, 3, 2 }; // Available Resources

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	
	for(int i=0;i<n;i++)
	{
	if(f[i]==0)
	{
		flag=0;
		printf("The following system is not safe");
		break;
	}
	}
	
	if(flag==1)
	{
	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);
	}
	

	return (0);

	// This code is contributed by Deep Baldha (CandyZack)
}
