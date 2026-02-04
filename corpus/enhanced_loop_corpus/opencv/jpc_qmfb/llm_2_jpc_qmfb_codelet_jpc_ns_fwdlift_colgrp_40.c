#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pre-incremented pointers
    // Instead of incrementing hptr2 and lptr2 after each operation, we process elements
    // using fixed offsets from the base pointer, accessing consecutive locations.
    jpc_fix_t *hbase = hptr2;
    jpc_fix_t *lbase = lptr2;
    for (i = 0; i < 16; ++i) {
        hbase[i] = hbase[i] + (
            (jpc_fix_t)(
                ((jpc_fix_big_t)(
                    (jpc_fix_t)(2. * (-1.5861343420599241) * ((double)(((jpc_fix_t)(1)) << 13)))
                ) * (jpc_fix_big_t)(lbase[i])
            ) >> 13)
        );
    }
    // Update global pointers to reflect advancement
    hptr2 += 16;
    lptr2 += 16;
}
