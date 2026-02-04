#include <stdio.h>

double rms[5];
int m;

void init_vars() {
    for (int i = 0; i < 5; i++) {
        rms[i] = 0.0;
    }
    m = 0;
}