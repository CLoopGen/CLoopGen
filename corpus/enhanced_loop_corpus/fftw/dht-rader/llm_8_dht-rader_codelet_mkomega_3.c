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
for (i = 1; i < n - 1; ++i) {
    for (j = 0; j < 3; ++j) {
        omega[npad - i] += omega[n - 1 - i] * omega[n - 1 - i];
        omega[npad - i] /= (omega[npad - i] + 1e-9);
    }
}
}
