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
INT j;
for (i = 1; i + i < n; ++i) {
    for (j = 0; j < 1; ++j) {
        r[i] = rio[i * is];
        r[n - i] = iio[i * is];
    }
}
}
