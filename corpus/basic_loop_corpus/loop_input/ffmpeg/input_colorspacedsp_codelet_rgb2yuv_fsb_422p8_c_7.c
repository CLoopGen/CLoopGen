#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int w;
int *rnd_scratch[3][2];
int x;
int rnd;

void init_vars() {
    const int data_size = 64 * 1024 * 1024; // ~64MB total data to target ~0.01s runtime
    w = data_size / sizeof(int);

    // Allocate memory for each required scratch array
    for (int i = 1; i <= 2; i++) {
        for (int j = 0; j < 2; j++) {
            rnd_scratch[i][j] = (int*)calloc(w, sizeof(int));
            if (!rnd_scratch[i][j]) {
                exit(1);
            }
        }
    }

    // Initialize rnd with a non-zero value
    rnd = 42;
}

// Ensure all extern references are satisfied