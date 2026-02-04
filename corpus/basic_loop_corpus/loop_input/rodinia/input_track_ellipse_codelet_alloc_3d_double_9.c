#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x = 1024;
int y = 256;
int z = 4;
double *data;
double **pointers_to_data;
int i;

void init_vars() {
    size_t total_elements = (size_t)x * y;
    size_t data_size = total_elements * z;

    data = (double*)calloc(data_size, sizeof(double));
    if (!data) exit(1);

    pointers_to_data = (double**)calloc(total_elements, sizeof(double*));
    if (!pointers_to_data) exit(1);
}