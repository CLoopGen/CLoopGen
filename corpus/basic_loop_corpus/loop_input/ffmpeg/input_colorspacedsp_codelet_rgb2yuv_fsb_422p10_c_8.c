#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 1 << 20; // Approximately 1MB of data (assuming int is 4 bytes)
int x;
int rnd = 0xdeadbeef;

static int *rnd_scratch_storage[3][2];
int *rnd_scratch[3][2];

void init_vars() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            rnd_scratch[i][j] = malloc(w * sizeof(int));
            if (!rnd_scratch[i][j]) {
                exit(1);
            }
        }
    }
    rnd = rand();
}