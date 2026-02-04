#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long long mt[312];
int i;
unsigned long long x;
unsigned long long mag01[2];

void init_vars() {
    for (int j = 0; j < 312; j++) {
        mt[j] = 0x12345678UL + j;
    }
    i = 0;
    x = 0;
    mag01[0] = 0x0UL;
    mag01[1] = 0x9908b0dfUL;
}