#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (numcols > 0) {
        int block_size = 4;
        int i;
        for (i = 0; i <= numcols - block_size; i += block_size) {
            for (int j = 0; j < block_size; ++j) {
                ((lptr2[0]) = ((lptr2[0]) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)((((0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(((hptr2[0]) + (hptr2[stride]))))) >> (13))))));
                ++lptr2;
                ++hptr2;
            }
        }
        for (; i < numcols; ++i) {
            ((lptr2[0]) = ((lptr2[0]) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)((((0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(((hptr2[0]) + (hptr2[stride]))))) >> (13))))));
            ++lptr2;
            ++hptr2;
        }
    }
}
