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
    INT stride_offset = i * is;
    r[2 * i] = rio[stride_offset];       // Strided write to r: even indices
    r[2 * i + 1] = iio[stride_offset];   // Interleaved write from iio
}
}
