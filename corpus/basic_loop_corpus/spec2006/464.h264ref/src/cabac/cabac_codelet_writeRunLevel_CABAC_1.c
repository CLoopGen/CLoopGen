#include <stdio.h>

#include <inttypes.h>

extern int coeff[64];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; pos < 64; pos++)
    coeff[pos] = 0;

}
