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
for (i = 1; i < n; ++i) {
    r[i] = rio[i * is] + iio[i * is] - rio[(i+1) * is] + (r[i-1] * 0.5);
    if (n - i >= 0) {
        r[n - i] = iio[i * is] * rio[i * is] + r[n - i];
    }
}
}
