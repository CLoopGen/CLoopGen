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
INT j;
for (i = 1; i + i < n; ++i) {
    j = i * os;
    rio[j] = r[i];
    iio[j] = r[n - i];
}
}
