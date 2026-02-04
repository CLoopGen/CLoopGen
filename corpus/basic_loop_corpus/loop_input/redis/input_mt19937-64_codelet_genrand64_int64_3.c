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
        mt[j] = 0x8000000000000000ULL + j;
    }
    mag01[0] = 0x00000000ULL;
    mag01[1] = 0x9908b0dfULL;
    i = 0;
    x = 0;
}