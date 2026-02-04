#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern doublereal e;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp = 0.0;
    for (k = *n; k >= 1; --k) {
        temp += z__[k];
    }
    e += temp;
}
