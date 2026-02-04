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
for (i = 2; i < n - 2; ++i) {
    omega[npad - i] = omega[n - 1 - i] + omega[n - i] - omega[n - 2 - i];
    omega[npad - (i-1)] = omega[n - i];
}
}
