#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int Alphabet_size = 20;
char Degenerate[24][20] = {0};
int DegenCount[24] = {0};
float *counters;
char symidx = 0;
float wt = 1.0f;
int x;

void init_vars() {
    for (int i = 0; i < 24; i++) {
        DegenCount[i] = 1 + (i % 20);
        for (int j = 0; j < 20; j++) {
            if (j < DegenCount[i]) {
                Degenerate[i][j] = 1;
            } else {
                Degenerate[i][j] = 0;
            }
        }
    }

    Alphabet_size = 20;
    symidx = 5;
    wt = 1.5f;

    counters = (float*)calloc(Alphabet_size, sizeof(float));
    if (!counters) {
        exit(1);
    }
}