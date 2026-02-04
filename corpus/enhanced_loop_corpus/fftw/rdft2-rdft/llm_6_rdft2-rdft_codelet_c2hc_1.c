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
        r[i] = rio[i * is];
        r[i] += r[i - 1]; // Introduce WAW and RAW loop-carried dependency: each iteration depends on the previous r[i-1]
        r[n - i] = iio[i * is];
    }
}
