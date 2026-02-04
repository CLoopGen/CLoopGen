#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int l;
extern  double x;
extern double bym;
extern double by;
extern double byp;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 1;
    for (j = 1; j < l; j += stride) {
        byp = (2.0 * j + 1.0) * by / x - bym;
        bym = by;
        by = byp;
        stride = 1 + ((int)(by * 10.0) % 3); // Adaptive stride based on scaled value of 'by'
    }
}
