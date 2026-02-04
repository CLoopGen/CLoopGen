#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

extern INT n;
extern R *r;
extern R *rio;
extern R *iio;
extern INT os;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT stride = 2;
for (i = 1; i + i < n; ++i) {
    INT idx = i * stride;
    rio[idx * os] = r[i];
    iio[idx * os] = r[n - i];
}
}
