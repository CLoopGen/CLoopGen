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
R temp_rio, temp_iio;
for (i = 1; i + i < n; ++i) {
    temp_rio = r[i];
    temp_iio = r[n - i];
    rio[i * os] = temp_rio;
    iio[i * os] = temp_iio;
}
}
