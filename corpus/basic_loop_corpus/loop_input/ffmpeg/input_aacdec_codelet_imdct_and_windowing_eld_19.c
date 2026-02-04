#include <stdlib.h>
#include <stdint.h>

typedef float INTFLOAT;

INTFLOAT *buf;
int i;
int n;

void init_vars() {
    n = 1 << 24; // Approximately 16.7 million elements, ~64 MB of data
    buf = (INTFLOAT *)aligned_alloc(32, n * sizeof(INTFLOAT));
    
    for (int j = 0; j < n; j++) {
        buf[j] = (INTFLOAT)(j % 100);
    }
}