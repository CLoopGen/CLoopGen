#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < numcols; i += step) {
        // Unroll the loop by processing two iterations at once
        if (i + 1 < numcols) {
            lptr2[0] -= (hptr2[0] + hptr2[stride] + 2) >> 2;
            ++lptr2;
            ++hptr2;

            lptr2[0] -= (hptr2[0] + hptr2[stride] + 2) >> 2;
            ++lptr2;
            ++hptr2;
        } else {
            // Handle odd numcols case
            lptr2[0] -= (hptr2[0] + hptr2[stride] + 2) >> 2;
            ++lptr2;
            ++hptr2;
        }
    }
}
