#include <stdio.h>

double errnm[5];
int m;

void init_vars() {
    for (int i = 0; i < 5; i++) {
        errnm[i] = 0.0;
    }
    m = 0;
}