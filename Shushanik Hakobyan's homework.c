/*
Write a C program to sort an array of integers entered by the user.
Ask the user for the number of elements they want to sort, then read
array elements into the dynamically created array. The sorting should
be done in a separate function.
– Write a Makefile for the program.
– Compile using optimized and debug modes.
– Set breakpoint in the sorting function, and run the program step by
step using GDB.
– Intentionally make a memory leak and detect it using Valgrind.
– Document code using Doxygen format and generate
documentation for it.*/
#include <stdio.h>
#include <stdlib.h>

void sortArray(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int *array = malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Invalid input detected.\n");
            free(array);
            return 1;
        }
    }

    sortArray(array, size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}
