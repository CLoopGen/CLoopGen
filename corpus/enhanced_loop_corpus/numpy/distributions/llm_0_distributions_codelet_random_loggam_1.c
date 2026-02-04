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
for (int64_t i = 0; i < 1; i++) {
    for (k = 8; k >= 0; k--) {
        gl0 *= x2;
        gl0 += a[k];
    }
}
}
