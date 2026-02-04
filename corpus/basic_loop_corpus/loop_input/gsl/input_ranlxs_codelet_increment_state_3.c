#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int next[12];
double shift;
int k;
double *xdbl;
double *ydbl;
unsigned int ir;

void init_vars() {
    const size_t data_size = 16777216; // 16M doubles = 128MB
    
    xdbl = (double*)aligned_alloc(32, data_size * sizeof(double));
    ydbl = (double*)aligned_alloc(32, data_size * sizeof(double));
    
    if (!xdbl || !ydbl) {
        exit(1);
    }
    
    for (size_t i = 0; i < data_size; i++) {
        xdbl[i] = (double)(i & 511);
        ydbl[i] = 0.0;
    }
    
    shift = 1.5;
    ir = 5;
    
    for (int i = 0; i < 12; i++) {
        if (i == 0) {
            next[i] = 7;
        } else if (i == 7) {
            next[i] = 3;
        } else if (i == 3) {
            next[i] = 1;
        } else if (i == 1) {
            next[i] = 0;
        } else {
            next[i] = (i + 1) % 12;
        }
    }
    
    k = next[ir];
}