#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/time.h>

int N;
int *dindex;
int i;

void init_vars() {
    struct timeval tv_start, tv_end;
    double elapsed = 0.0;
    long long count = 1000000; // Start with 1M elements

    while (elapsed < 0.01) {
        count *= 2;
        if (count > 268435456) { // Cap at ~1GB for int array (268435456 * 4 bytes = 1GB)
            count = 268435456;
            break;
        }

        N = count;
        dindex = (int*)malloc(N * sizeof(int));
        if (!dindex) {
            count /= 2;
            break;
        }

        gettimeofday(&tv_start, NULL);
        for (i = 0; i < N - 2; i++) {
            dindex[i] = i + 2;
        }
        gettimeofday(&tv_end, NULL);

        elapsed = (tv_end.tv_sec - tv_start.tv_sec) + (tv_end.tv_usec - tv_start.tv_usec) / 1000000.0;

        free(dindex);
    }

    N = count;
    dindex = (int*)malloc(N * sizeof(int));
    if (!dindex) {
        N = 0;
    }
}