#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int max_v;
int* c_array;
int arraysize;

void init_vars() {
    arraysize = 65536; // ~256KB of data, sufficient for ~0.01 sec runtime
    c_array = (int*)malloc(sizeof(int) * arraysize);
    if (!c_array) {
        exit(1);
    }
    for (int i = 0; i < arraysize; i++) {
        c_array[i] = rand() % 10000;
    }
    max_v = c_array[0];
    x = 0;
}