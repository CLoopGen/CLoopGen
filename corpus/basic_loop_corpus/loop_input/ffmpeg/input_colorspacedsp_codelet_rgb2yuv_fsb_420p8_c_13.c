#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w;
int *rnd_scratch[3][2];
int x;
int rnd;

void init_vars() {
    w = 64 * 1024 * 1024; // 64M elements for ~0.01 sec runtime on typical CPU
    rnd = 42;

    for (int i = 1; i <= 2; i++) {
        rnd_scratch[i][0] = malloc(w * sizeof(int));
        rnd_scratch[i][1] = malloc(w * sizeof(int));
        if (!rnd_scratch[i][0] || !rnd_scratch[i][1]) {
            exit(1);
        }
    }

    for (int i = 1; i <= 2; i++) {
        for (int j = 0; j < w; j++) {
            rnd_scratch[i][0][j] = 0;
            rnd_scratch[i][1][j] = 0;
        }
    }
}