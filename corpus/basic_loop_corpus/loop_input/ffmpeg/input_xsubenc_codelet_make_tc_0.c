#include <stdint.h>
#include <stdlib.h>

uint64_t ms;
int *tc;
int tc_divs[3];
int i;

void init_vars() {
    tc = (int *)malloc(3 * sizeof(int));
    if (!tc) exit(1);
    ms = 123456789ULL;
    tc_divs[0] = 1000;
    tc_divs[1] = 60;
    tc_divs[2] = 60;
}