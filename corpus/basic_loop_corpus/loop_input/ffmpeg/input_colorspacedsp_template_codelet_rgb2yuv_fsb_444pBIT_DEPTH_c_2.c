#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 1048576; // ~1MB of data (assuming int is 4 bytes: 1048576 * 4 * 2 = ~8.4MB total accessed)
int x;
int rnd = 42;

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