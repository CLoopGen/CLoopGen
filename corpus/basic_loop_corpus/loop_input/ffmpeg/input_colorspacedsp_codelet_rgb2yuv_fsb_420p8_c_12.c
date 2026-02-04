#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int w = 64 * 1024 * 1024 / sizeof(int); // ~256MB total data, split across arrays
int x;
int rnd = 0xdeadbeef;

int *rnd_scratch[3][2];

void init_vars() {
    srand(time(NULL));
    rnd = rand();

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            rnd_scratch[i][j] = (int*)calloc(w, sizeof(int));
            if (!rnd_scratch[i][j]) {
                fprintf(stderr, "Allocation failed\n");
                exit(1);
            }
        }
    }

    w = 64 * 1024 * 1024 / sizeof(int);
}