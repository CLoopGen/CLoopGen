#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

unsigned int i;
double xnum;
double xden;
double absx;
double c[9];
double d[8];

void init_vars() {
    xnum = 1.5;
    xden = 1.0;
    absx = 0.75;
    
    for (int j = 0; j < 9; j++) {
        c[j] = j * 0.5 + 1.0;
    }
    
    for (int j = 0; j < 8; j++) {
        d[j] = j * 0.3 + 0.5;
    }
}