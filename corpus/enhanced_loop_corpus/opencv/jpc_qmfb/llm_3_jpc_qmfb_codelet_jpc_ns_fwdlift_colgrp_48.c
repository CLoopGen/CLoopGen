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
    for (i = 0; i < 16; ++i) {
        int idx = (i & 7) + ((i & 8) << 1); // Non-sequential, semi-scrambled index: 0..7 then 16..23
        ((hptr2[idx]) = ((hptr2[idx]) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (0.88291107553093395)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(lptr2[idx]))) >> (13))))));
    }
    // Update pointers to reflect logical progression over scattered region
    lptr2 += 24;
    hptr2 += 24;
}
