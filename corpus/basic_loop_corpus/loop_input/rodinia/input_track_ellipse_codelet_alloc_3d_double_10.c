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
    // Allocate pointers_to_data as an array of double pointers
    pointers_to_data = (double**)calloc(x * y, sizeof(double*));
    if (!pointers_to_data) {
        exit(1);
    }

    // Allocate each pointer in pointers_to_data to point to a block of 8 doubles (64 bytes each -> ~512KB total)
    for (int j = 0; j < x * y; j++) {
        pointers_to_data[j] = (double*)calloc(8, sizeof(double));
        if (!pointers_to_data[j]) {
            exit(1);
        }
    }

    // Allocate pointers_to_pointers as an array of double**
    pointers_to_pointers = (double***)calloc(x, sizeof(double**));
    if (!pointers_to_pointers) {
        exit(1);
    }
}