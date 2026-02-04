#include <stdio.h>

double x[14003];
int i;

void init_vars() {
    for (int j = 0; j < 14003; j++) {
        x[j] = 0.0;
    }
}