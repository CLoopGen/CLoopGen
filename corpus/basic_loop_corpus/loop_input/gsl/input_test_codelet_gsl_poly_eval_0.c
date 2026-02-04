#include <stdlib.h>
#include <stdint.h>

double c[2097152]; // ~16.8 MB to target ~0.01 sec runtime
int len;
double x;
int i;
double ans;

void init_vars() {
    len = 2097152;
    x = 1.5;
    ans = 0.0;
    for (int j = 0; j < len; j++) {
        c[j] = (double)(j & 255);
    }
}