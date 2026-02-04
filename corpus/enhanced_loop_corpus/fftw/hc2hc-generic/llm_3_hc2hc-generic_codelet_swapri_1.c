#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *IO;
extern INT r;
extern INT s;
extern INT jstart;
extern INT jend;
extern INT k;
extern INT ms;
extern INT js;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k + k < r; ++k) {
    INT offset_r = (k + 1) * ms - js;
    INT offset_i = (r - k) * ms - js;
    INT j;
    for (j = jstart; j < jend; j += 1) {
        INT idx_r = offset_r + (jstart - j) * s;
        INT idx_i = offset_i + (jstart - j) * s;
        R t = IO[idx_r];
        IO[idx_r] = IO[idx_i];
        IO[idx_i] = t;
    }
}
}
