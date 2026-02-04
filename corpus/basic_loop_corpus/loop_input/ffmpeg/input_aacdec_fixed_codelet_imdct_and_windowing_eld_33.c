#include <stdlib.h>
#include <stdint.h>

typedef int INTFLOAT;

INTFLOAT *buf;
int i;
int n;

void init_vars() {
    n = 64 * 1024 * 1024; // 64M elements, ~256MB for int data
    buf = (INTFLOAT*)aligned_alloc(32, n * sizeof(INTFLOAT));
    if (!buf) exit(1);
    for (int j = 0; j < n; j++) {
        buf[j] = rand();
    }
    i = 0;
}