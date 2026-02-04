#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *ref;
char *k1;
int col;
int r1;
int *canons1;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of input data

    k1 = (char *)malloc(data_size);
    ref = (int *)malloc(data_size * sizeof(int));
    canons1 = (int *)malloc(data_size * sizeof(int));

    for (size_t i = 0; i < data_size - 1; i++) {
        int c = rand() % 128;
        k1[i] = (char)c;
        ref[i] = rand() % 2;
    }
    k1[data_size - 1] = '\x00'; // null terminate

    col = 0;
    r1 = 0;
}