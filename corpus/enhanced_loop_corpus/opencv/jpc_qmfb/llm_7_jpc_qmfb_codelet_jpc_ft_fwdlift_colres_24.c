#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t acc = 0;
    for (i = 0; i < numcols; ++i) {
        acc += (hptr2[i] + 1) >> 1; // Remove pointer increment side effects; use indexed access and accumulate locally
    }
    lptr2[0] += acc; // Move the update outside the loop — eliminate loop-carried RAW dependency on lptr2
    // Adjust pointers post-loop to preserve external state if needed (assuming no further use, otherwise add: lptr2 += numcols; hptr2 += numcols;)
}
