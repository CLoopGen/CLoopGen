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
for (i = 1; i + i < n; ++i) {
    for (INT k = 0; k < 1; ++k) {
        rio[i * os] = r[i];
        iio[i * os] = r[n - i];
    }
}
}
