#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime
int j = 1;
int k = 2;
int n;
int64_t s;

int32_t *x;

void init_vars() {
    x = aligned_alloc(32, sizeof(int32_t) * (len + 3));
    if (!x) {
        exit(1);
    }
    for (int i = 0; i < len + 3; i++) {
        x[i] = (int32_t)(i & 0xFF);
    }
    s = 0;
}