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
for (i = 1; i + i < n; ++i) {
    if (i * is >= 0) {
        r[i] = rio[i * is];
        r[n - i] = iio[i * is];
    }
}
}
