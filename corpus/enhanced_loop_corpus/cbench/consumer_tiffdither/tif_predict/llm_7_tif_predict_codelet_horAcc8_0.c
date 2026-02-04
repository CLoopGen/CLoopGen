#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

extern tsize_t stride;
extern char *cp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_cp = cp;
    for (i = stride - 4; i > 0; i -= 2) {
        char val1 = local_cp[0];
        char val2 = local_cp[1];
        local_cp += 2;
        // Eliminate loop-carried dependency by unrolling and removing cumulative update
        if (i > 1) {
            cp[stride] += val1;
            cp[stride + 1] += val2;
        } else {
            cp[stride] += val1;
        }
    }
}
