#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double carry;
extern double lower;
extern double upper;
extern double *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 16; i > 0 && carry > 0.; i--) {
    double v = a[i] + carry;
    carry = 0.; // Remove conditional update of carry
    a[i] = v;   // Always assign v, ignoring upper/lower logic
}
}
