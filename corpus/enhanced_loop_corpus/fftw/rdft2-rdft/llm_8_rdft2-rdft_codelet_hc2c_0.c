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
for (i = 2; i + i < n; i += 2) {
    rio[i * os] = r[i];
    iio[i * os] = r[n - i];
    rio[(i-1) * os] = r[i-1];
    iio[(i-1) * os] = r[n - (i-1)];
}
}
