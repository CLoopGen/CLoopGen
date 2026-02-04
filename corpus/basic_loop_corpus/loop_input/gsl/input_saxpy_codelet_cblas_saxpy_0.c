#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

float alpha;
float *X;
float *Y;
int i;
int m;

static float X_data[65536];
static float Y_data[65536];

void init_vars() {
    struct timeval tv_start, tv_end;
    double elapsed;
    int repeat = 1;

    alpha = 2.5f;
    m = 65536;
    X = X_data;
    Y = Y_data;

    for (int j = 0; j < m; j++) {
        X[j] = (float)(j % 128) + 1.0f;
        Y[j] = (float)(j % 128) + 2.0f;
    }

    gettimeofday(&tv_start, NULL);
    while (1) {
        for (int r = 0; r < repeat; r++) {
            for (i = 0; i < m; i++) {
                Y[i] += alpha * X[i];
            }
        }
        gettimeofday(&tv_end, NULL);
        elapsed = (tv_end.tv_sec - tv_start.tv_sec) + (tv_end.tv_usec - tv_start.tv_usec) / 1e6;
        if (elapsed >= 0.01) break;
        repeat *= 2;
    }

    for (int j = 0; j < m; j++) {
        Y[j] = (float)(j % 128) + 2.0f;
    }
}