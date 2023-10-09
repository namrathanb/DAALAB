//Application program 1 to sort the attendance register of students using Quick sort
/*An attendance register is commonly used to keep track of students'
presence in a class or an event. Sorting the names in the attendance
register alphabetically is essential for easy access and analysis. The
task is to develop a program that takes a list of names in an
attendance register as input and sorts them alphabetically using the
quick sort algorithm. The program should read the names from a file
or accept user input, sort them, and display the sorted list of names.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* str1, char* str2) {
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

int partition(char arr[][100], int low, int high) {
    char pivot[100];
    strcpy(pivot, arr[high]);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(char arr[][100], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void inputNamesFromTerminal(char names[][100], int numNames) {
    printf("Enter names in the attendance register:\n");
    for (int i = 0; i < numNames; i++) {
        scanf("%s", names[i]);
    }
}

int inputNamesFromFile(char names[][100]) {
    char filename[100];
    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file '%s'\n", filename);
        return -1;
    }

    printf("Reading names from file '%s'\n", filename);
    int numNames = 0;
    while (fscanf(file, "%s", names[numNames]) == 1) {
        numNames++;
    }

    fclose(file);
    return numNames;
}

void writeSortedNamesToFile(char names[][100], int numNames) {
    FILE* file = fopen("sorted_names.txt", "w");
    if (file == NULL) {
        printf("Error creating file 'sorted_names.txt'\n");
        return;
    }

    printf("Writing sorted names to 'sorted_names.txt'\n");
    for (int i = 0; i < numNames; i++) {
        fprintf(file, "%s\n", names[i]);
    }

    fclose(file);
}

int main() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Input names from terminal\n");
    printf("2. Input names from file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int numNames;
    char names[1000][100];

    switch (choice) {
        case 1:
            printf("Enter the number of names in the attendance register: ");
            scanf("%d", &numNames);
            inputNamesFromTerminal(names, numNames);
            break;
        case 2:
            numNames = inputNamesFromFile(names);
            if (numNames == -1) {
                return 1; // Error occurred while reading from the file
            }
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            return 1;
    }

    quickSort(names, 0, numNames - 1);

    printf("\nSorted names in the attendance register:\n");
    for (int i = 0; i < numNames; i++) {
        printf("%s\n", names[i]);
    }

    writeSortedNamesToFile(names, numNames);

    return 0;
}
