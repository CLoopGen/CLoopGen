#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (stride of 2)
    // Instead of accessing consecutive elements, we access every second element.
    // This changes spatial locality and may affect cache behavior.
    for (i = 0; i < numcols; i += 2) {
        if (i + 0 < numcols) {
            ((lptr2[0]) = ((lptr2[0]) + ((-(((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(hptr2[0]))) >> (13))))))));
        }
        lptr2 += 2;
        hptr2 += 2;
    }
}
