#include <inttypes.h>

typedef unsigned long UV;
typedef double NV;

UV power;
NV result;
NV base;
int n;

void init_vars() {
    power = 0x1ABCDEFUL;  // Large enough to ensure multiple loop iterations
    result = 1.0;
    base = 2.5;
    n = 0;
}