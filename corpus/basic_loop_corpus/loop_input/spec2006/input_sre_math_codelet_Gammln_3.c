#include <inttypes.h>

int i;
double tmp;
double value;
double cof[11];

void init_vars() {
    tmp = 11.0;
    value = 0.0;
    for (int j = 0; j < 11; j++) {
        cof[j] = (double)(j + 1) * 1.5;
    }
}