#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w;
int *rnd_scratch[3][2];
int x;
int rnd;

void init_vars() {
    w = 65536; 
    rnd = 42;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            rnd_scratch[i][j] = (int*)calloc(w, sizeof(int));
        }
    }
}