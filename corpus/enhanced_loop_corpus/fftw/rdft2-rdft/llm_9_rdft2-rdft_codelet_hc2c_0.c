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
for (i = 1; i < n && i + i < n; i++) {
    R temp1 = r[i] * r[i] + 0.5;
    R temp2 = r[n - i] * r[n - i] - 0.5;
    rio[i * os] = temp1;
    iio[i * os] = temp2;
    rio[i * os] += r[i] * 0.1;
    iio[i * os] -= r[n - i] * 0.1;
}
}
