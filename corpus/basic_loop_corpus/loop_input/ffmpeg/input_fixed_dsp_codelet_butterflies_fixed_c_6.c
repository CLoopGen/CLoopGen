#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

int len;
int i;
unsigned int *v1;
int *v2;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    len = 1 << 20; // 1 million elements ~ 4MB data per array

    v1 = (unsigned int *)aligned_alloc(32, len * sizeof(unsigned int));
    v2 = (int *)aligned_alloc(32, len * sizeof(int));

    if (!v1 || !v2) {
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        v1[j] = (unsigned int)(j % 100000 + 1);
        v2[j] = j % 50000 + 1;
    }

    do {
        gettimeofday(&end, NULL);
        double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
        if (elapsed >= 0.01) break;

        for (int iter = 0; iter < len; iter++) {
            int t = v1[iter] - v2[iter];
            v1[iter] += v2[iter];
            v2[iter] = t;
        }
    } while (1);
}