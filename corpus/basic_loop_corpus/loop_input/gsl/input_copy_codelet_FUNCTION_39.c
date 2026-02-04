#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/time.h>

size_t M;
size_t N;
size_t i;
size_t j;

void init_vars() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec * 1000000 + tv.tv_usec);

    size_t target_iterations = 50000000; 
    M = rand() % 7000 + 3000;  
    N = M + (rand() % 5000 + 2000);  

    if (M > N) {
        size_t temp = M;
        M = N;
        N = temp;
    }

    size_t actual_iters = 0;
    for (size_t ii = 0; ii < M; ii++) {
        actual_iters += (N - (ii + 1)) > 0 ? (N - (ii + 1)) : 0;
    }

    double ratio = (double)target_iterations / (actual_iters + 1);
    if (ratio > 1.0) {
        size_t scale = (size_t)(ratio * 1.1);
        M = (M * scale < 16384) ? M * scale : M;
        N = (N * scale < 32768) ? N * scale : N;
    }

    if (M == 0 || N <= M) {
        M = 8000;
        N = 16000;
    }
}