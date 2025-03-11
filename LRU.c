#include <stdio.h>
#include <stdlib.h>

int main() {  
    int n, size = 3;
    printf("Enter the Number of Pages: ");
    scanf("%d", &n);
    int* ref_string = (int*)malloc(n * sizeof(int));
    printf("Enter the Page sequence: ");
    for (int j = 0; j < n; j++) {
        scanf("%d", &ref_string[j]);
    }
    int* pages = (int*)malloc(size * sizeof(int));
    int faults = 0;
    int hits = 0;
    int i, j;

    // Initialize the pages array to -1, indicating no page in memory
    for (i = 0; i < size; i++) {
        pages[i] = -1;
    }

    for (i = 0; i < n; i++) {
        int ref_page = ref_string[i];
        int page_found = 0;

        // Check if the reference page already exists in memory
        for (j = 0; j < size; j++) {
            if (pages[j] == ref_page) {
                page_found = 1;
                hits++;  // Page hit
                break;
            }
        }

        // If the page is not found in memory, replace a page with the new page
        if (!page_found) {
            faults++;  // Page fault

            // Find the first empty slot in memory
            for (j = 0; j < size; j++) {
                if (pages[j] == -1) {
                    pages[j] = ref_page;
                    break;
                }
            }

            // If memory is full, replace the least recently used page
            if (j == size) {
                // Find the index of the least recently used page
                int min_index = 0;
                for (j = 1; j < size; j++) {
                    if (pages[j] < pages[min_index]) {
                        min_index = j;
                    }
                }
                // Replace the least recently used page
                pages[min_index] = ref_page;
            }
        }
    }

    // Printing the number of page hits and page faults
    printf("Total number of Page Hits: %d\n", hits);
    printf("Total number of Page Faults: %d\n", faults);

    free(ref_string);
    free(pages);

    return 0;
}