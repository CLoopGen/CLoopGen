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
unsigned long temp;

void init_vars() {
    temp = 1UL << 20; // Large power of 2 to ensure many divisions by 2, few by others
}