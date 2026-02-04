#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int *dig;
int *chr;
int length;
int j;

void init_vars() {
    length = 10000000; // Approximately 10M elements for ~0.01 sec runtime

    dig = (int*)malloc(length * sizeof(int));
    chr = (int*)malloc(sizeof(int));

    *chr = 0;

    for (int i = 0; i < length; i++) {
        dig[i] = i % 10; // Initialize with digits 0-9 cyclically
    }
}