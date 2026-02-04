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
    for (i = 9; i > 0 && carry > 0. && (a[i-1] + carry > upper || 1); --i) {
        double v = a[i-1] + carry;
        carry = (v > upper);
        a[i-1] = (carry) ? lower : v;
    }
}
