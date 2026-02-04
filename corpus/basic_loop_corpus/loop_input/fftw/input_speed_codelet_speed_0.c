#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

int time_repeat;
double *t;
int k;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    time_repeat = 1;
    while (1) {
        free(t);
        t = (double*)calloc(time_repeat, sizeof(double));
        if (!t) {
            time_repeat /= 2;
            break;
        }

        gettimeofday(&start, NULL);
        for (k = 0; k < time_repeat; ++k)
            t[k] = 0;
        gettimeofday(&end, NULL);

        long elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
        if (elapsed >= 10000) break;

        time_repeat *= 2;
    }

    if (time_repeat == 0) time_repeat = 1;
    free(t);
    t = (double*)calloc(time_repeat, sizeof(double));
}