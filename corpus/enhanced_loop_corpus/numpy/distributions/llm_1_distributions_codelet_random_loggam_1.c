#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x2;
extern double gl0;
extern int64_t k;
extern double a[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 8; k >= 0; k--) {
    for (int64_t j = 0; j < 1; j++) {
        gl0 *= x2;
        gl0 += a[k];
    }
}
}
