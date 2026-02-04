#include <stdio.h>
#include <inttypes.h>

int targ_bits[2];
int mean_bits;
int ch;
int numchn;

void init_vars() {
    numchn = 2;
    mean_bits = 2400;
    targ_bits[0] = 3000;
    targ_bits[1] = 4000;
}