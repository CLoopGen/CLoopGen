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
        int idx = i * 2; // Strided access with step 2
        ((hptr2[idx]) = ((hptr2[idx]) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (0.88291107553093395)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(lptr2[idx]))) >> (13))))));
    }
    hptr2 += 32; // Advance pointers as in original (simulate ++hptr2 effect over strided indices)
    lptr2 += 32;
}
