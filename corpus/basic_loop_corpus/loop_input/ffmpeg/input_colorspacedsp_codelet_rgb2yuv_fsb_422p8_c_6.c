#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime
int x;
int rnd = 0xdeadbeef;

static int *rnd_scratch_data[3][2];
int *rnd_scratch[3][2] = {
    { NULL, NULL },
    { NULL, NULL },
    { NULL, NULL }
};

void init_vars() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            rnd_scratch_data[i][j] = malloc(w * sizeof(int));
            if (!rnd_scratch_data[i][j]) {
                exit(1);
            }
            rnd_scratch[i][j] = rnd_scratch_data[i][j];
        }
    }
}