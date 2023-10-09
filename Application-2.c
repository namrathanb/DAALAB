/*A contact list often contains mobile numbers that need to be sorted
for easy access and management. The task is to develop a program
that takes a list of mobile numbers in a contact list as input and sorts
them using the merge sort algorithm. The program should read the
mobile numbers from a file or accept user input, sort them, and
display the sorted list of mobile numbers.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Merge Function to merge sorted subarrays
void merge(char arr[][12], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    char L[n1][12], R[n2][12];

    for (i = 0; i < n1; i++)
        strcpy(L[i], arr[low + i]);
    for (j = 0; j < n2; j++)
        strcpy(R[j], arr[mid + 1 + j]);

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(arr[k], L[i]);
            i++;
        } else {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }

    while (j < n2) {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}

//Merge sort function to recursively divide and merge
void mergeSort(char arr[][12], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int n, option;

    printf("Choose input method:\n");
    printf("1. Enter mobile numbers manually\n");
    printf("2. Read mobile numbers from file\n");
    scanf("%d", &option);

    switch (option) {
      //To take input from user   
      case 1: {
            printf("Enter the number of mobile numbers in the contact list: ");
            scanf("%d", &n);

            char mobileNumbers[n][12];

            printf("Enter the mobile numbers:\n");
            for (int i = 0; i < n; i++) {
                scanf("%s", mobileNumbers[i]);
            }

            mergeSort(mobileNumbers, 0, n - 1);

            printf("\nSorted list of mobile numbers:\n");
            for (int i = 0; i < n; i++) {
                printf("%s\n", mobileNumbers[i]);
            }
            break;
        }
            //To take input from the file      
            case 2: {
            char filename[50];
            printf("Enter the filename: ");
            scanf("%s", filename);

            FILE *file = fopen(filename, "r");
            if (file == NULL) {
                printf("Failed to open the file.\n");
                return 1;
            }

            char mobileNumbers[1000][12]; // Assuming at most 1000 mobile numbers
            int n = 0;

            while (fscanf(file, "%s", mobileNumbers[n]) == 1) {
                n++;
            }

            fclose(file);

            mergeSort(mobileNumbers, 0, n - 1);

            printf("\nSorted list of mobile numbers:\n");
            for (int i = 0; i < n; i++) {
                printf("%s\n", mobileNumbers[i]);
            }

            // Writing to a new file
            FILE *outputFile = fopen("sorted_mobile_numbers.txt", "w");
            if (outputFile == NULL) {
                printf("Error opening file for writing.\n");
                return 1;
            }

            for (int i = 0; i < n; i++) {
                fprintf(outputFile, "%s\n", mobileNumbers[i]);
            }

            fclose(outputFile);
            printf("File created...");
            break;
        }
        default:
            printf("Invalid option.\n");
            break;
    }

    return 0;
}
