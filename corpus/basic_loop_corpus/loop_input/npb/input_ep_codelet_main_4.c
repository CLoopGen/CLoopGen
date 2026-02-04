#include <stdio.h>

int i;
double qq[10];

void init_vars() {
    i = 0;
    for (int j = 0; j < 10; j++) {
        qq[j] = 0.0;
    }
}