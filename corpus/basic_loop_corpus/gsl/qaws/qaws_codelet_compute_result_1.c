#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *r;
extern  double *cheb12;
extern size_t i;
extern double res12;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 13; i++) {
    res12 += r[i] * cheb12[i];
}

}
