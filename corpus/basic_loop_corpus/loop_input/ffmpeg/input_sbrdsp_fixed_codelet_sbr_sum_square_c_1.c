#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int (*x)[2];
int n;
uint64_t accu;
uint64_t accu0;
uint64_t accu1;
uint64_t accu2;
uint64_t accu3;
int i;
int nz;

void init_vars() {
    n = 1 << 23; // Approximately 8M integers = 16MB of data, suitable for ~0.01 sec runtime
    x = (int(*)[2])calloc(n, sizeof(int[2]));
    if (!x) exit(1);

    for (int idx = 0; idx < n; idx++) {
        x[idx][0] = rand() % 1000 - 500;
        x[idx][1] = rand() % 1000 - 500;
    }

    accu = 0;
    accu0 = 0;
    accu1 = 0;
    accu2 = 0;
    accu3 = 0;
    i = 0;
    nz = 0;
}