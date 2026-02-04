#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ni;
int *p;
int *q;
int i;
long sump;
long sumq;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data for sufficient runtime (~0.01 sec on modern CPU)
    ni = data_size / sizeof(int);
    
    p = (int*)aligned_alloc(32, data_size);
    q = (int*)aligned_alloc(32, data_size);
    
    if (!p || !q) {
        exit(1);
    }
    
    for (int j = 0; j < ni; ++j) {
        p[j] = (j % 100) + 1;
        q[j] = (j % 100) + 5;
    }
    
    sump = 0;
    sumq = 0;
    i = 0;
}