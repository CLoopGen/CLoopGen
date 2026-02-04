#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 1048576; // 1MB of integers (1048576 elements)
int x;
int rnd = 0xdeadbeef;

int *rnd_scratch[3][2];

void init_vars() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            rnd_scratch[i][j] = (int*)calloc(w, sizeof(int));
            if (!rnd_scratch[i][j]) {
                exit(1);
            }
        }
    }
}