#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

extern INT n;
extern INT npad;
extern R *omega;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT j;
for (j = 1; j < n - 1; ++j) {
    if (npad - j >= 0) {
        omega[npad - j] = omega[n - 1 - j];
    }
}
}
