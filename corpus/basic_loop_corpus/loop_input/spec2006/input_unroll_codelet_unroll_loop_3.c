#include <stdio.h>
#include <inttypes.h>

struct _factor {
    const int factor;
    int count;
};

struct _factor factors[4] = {
    { .factor = 2, .count = 10000 },
    { .factor = 3, .count = 10000 },
    { .factor = 5, .count = 10000 },
    { .factor = 7, .count = 10000 }
};

int i;
unsigned long temp;
int unroll_number;

void init_vars() {
    i = 3;
    temp = 1;
    unroll_number = 1;
}