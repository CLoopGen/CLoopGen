#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t udata[65535];
int32_t *data;
int n;
int i;

void init_vars() {
    n = 65535;
    data = (int32_t*)malloc(n * sizeof(int32_t));
    if (!data) {
        exit(1);
    }
    for (i = 0; i < n; i++) {
        data[i] = rand() - (RAND_MAX / 2);
    }
}