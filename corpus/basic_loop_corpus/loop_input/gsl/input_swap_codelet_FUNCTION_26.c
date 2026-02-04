#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

size_t K;
size_t i;
size_t j;

void init_vars() {
    struct timespec start, end;
    
    K = 1;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    while (1) {
        i = 0;
        for (i = 0; i < K; i++) {
            for (j = 0; j < i; j++) {
            }
        }
        
        clock_gettime(CLOCK_MONOTONIC, &end);
        double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        
        if (elapsed >= 0.01) break;
        
        if (K > 1000000) {
            K += 100000;
        } else {
            K = (size_t)(K * 1.5);
            if (K == 0) K = 1;
        }
    }
}