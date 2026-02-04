#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x = 10000;
int y = 50;

double **pointers_to_data;
double ***pointers_to_pointers;
int i;

void init_vars() {
    // Allocate pointers_to_data: array of double*
    pointers_to_data = (double**)calloc(x * y, sizeof(double*));
    if (!pointers_to_data) {
        exit(1);
    }

    // Allocate each double* to point to a block of 10 doubles to ensure valid data
    for (int idx = 0; idx < x * y; idx++) {
        pointers_to_data[idx] = (double*)calloc(10, sizeof(double));
        if (!pointers_to_data[idx]) {
            exit(1);
        }
    }

    // Allocate pointers_to_pointers: array of double**
    pointers_to_pointers = (double***)calloc(x, sizeof(double**));
    if (!pointers_to_pointers) {
        exit(1);
    }
}