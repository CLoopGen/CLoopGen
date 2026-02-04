#include <stdio.h>
#include <inttypes.h>

#define DEFAULT_TMAX 10000000

int tmax = DEFAULT_TMAX;
double _fict_[500];
int i;

void init_vars() {
    if (tmax > 500) {
        tmax = 500;
    }
    for (int j = 0; j < 500; j++) {
        _fict_[j] = 0.0;
    }
    i = 0;
}