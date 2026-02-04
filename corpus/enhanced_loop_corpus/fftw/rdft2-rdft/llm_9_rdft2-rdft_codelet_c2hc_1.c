#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

extern INT n;
extern R *rio;
extern R *iio;
extern INT is;
extern R *r;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i + (i >> 1) < n; i += 2) {
    r[i] = rio[i * is];
    r[n - i] = iio[i * is];
    r[i/2] = rio[(i/2) * is];
}
}
