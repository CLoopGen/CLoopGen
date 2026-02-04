#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w;
int *rnd_scratch[3][2];
int x;
int rnd;

void init_vars() {
    w = 64 * 1024 * 1024; // 64M elements for ~0.01 sec on modern CPU
    rnd = 42;

    // Allocate memory for each of the required scratch arrays
    for (int i = 1; i <= 2; i++) {
        for (int j = 0; j < 2; j++) {
            rnd_scratch[i][j] = (int*)calloc(w, sizeof(int));
            if (!rnd_scratch[i][j]) {
                exit(1);
            }
        }
    }

    // Ensure null out-of-bound pointers to avoid accidental use
    for (int j = 0; j < 2; j++) {
        rnd_scratch[0][j] = NULL;
    }
}