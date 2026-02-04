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
    R *pr = IO + (k + 1) * ms - js;
    R *pi = IO + (r - k) * ms - js;
    INT j;
    R temp_r, temp_i;
    for (j = jstart; j < jend; j += 1, pr -= s, pi -= s) {
        temp_r = *pr;
        temp_i = *pi;
        *pr = temp_i;
        *pi = temp_r;
    }
}
}
