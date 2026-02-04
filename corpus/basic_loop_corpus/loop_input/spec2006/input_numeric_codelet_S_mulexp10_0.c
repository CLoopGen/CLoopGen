#include <inttypes.h>

typedef int I32;
typedef double NV;

I32 exponent;
NV result;
NV power;
I32 bit;

void init_vars() {
    exponent = 1000000;
    result = 1.5;
    power = 1.1;
    bit = 0;
}