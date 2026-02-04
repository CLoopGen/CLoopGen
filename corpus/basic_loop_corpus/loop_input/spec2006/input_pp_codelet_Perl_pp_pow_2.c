#include <inttypes.h>

typedef unsigned long UV;

UV power;
UV result;
UV base;
int n;

void init_vars() {
    base = 3;
    result = 1;
    power = 987654321UL;
    n = 0;
}