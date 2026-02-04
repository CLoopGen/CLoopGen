#include <stdio.h>

double q[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
double gc = 0.0;
int i = 0;

void init_vars() {
    gc = 0.0;
    for (int j = 0; j < 10; j++) {
        q[j] = (double)(j + 1) * 1.0;
    }
}