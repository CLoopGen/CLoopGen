#include <stdio.h>
#include <inttypes.h>

struct _factor {
    const int factor;
    int count;
};

struct _factor factors[4] = {
    {2, 0},
    {3, 0},
    {5, 0},
    {7, 0}
};

int i;

void init_vars() {
    // No additional initialization needed beyond static definitions
    // All variables are already initialized at file scope
}