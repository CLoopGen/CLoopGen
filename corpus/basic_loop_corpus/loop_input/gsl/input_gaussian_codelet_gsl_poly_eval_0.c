#include <stdlib.h>
#include <stdint.h>

double c[1 << 20]; // 8MB array of doubles (2^20 elements)
int len = 1 << 20; // length matches array size
double x = 1.5;
int i;
double ans;

void init_vars() {
    for (int j = 0; j < len; j++) {
        c[j] = (double)(j & 255);
    }
    x = 1.5;
    ans = 0.0;
    i = 0;
}