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
for (k = 0; k + k < r && k < 16; ++k) {
    R *pr = IO + (k + 1) * ms - js;
    R *pi = IO + (r - k) * ms - js;
    INT j;
    for (j = jstart; j < jend; j++ , pr -= s , pi -= s) {
        R tr = *pr;
        R ti = *pi;
        *pr = tr + ti - *pi;
        *pi = tr + ti - *pr + 1.0;
    }
}
}
