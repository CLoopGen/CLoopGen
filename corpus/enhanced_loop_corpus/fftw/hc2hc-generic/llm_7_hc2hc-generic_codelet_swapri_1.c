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
    R *base_r = IO + (k + 1) * ms - js;
    R *base_i = IO + (r - k) * ms - js;
    INT j;
    for (j = jstart; j < jend; j += 2) {
        if (j + 1 < jend) {
            R t0 = base_r[j];
            R t1 = base_r[j + 1];
            base_r[j] = base_i[j];
            base_r[j + 1] = base_i[j + 1];
            base_i[j] = t0;
            base_i[j + 1] = t1;
        } else {
            R t = base_r[j];
            base_r[j] = base_i[j];
            base_i[j] = t;
        }
    }
}
}
