#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_nn = nn;
    int j;
    for (j = 0; j < 16 && local_nn > 1; j++) {
        local_nn = local_nn >> 1;
        i = j; // Introduce WAW dependency on i, updated each iteration
    }
    nn = local_nn; // Final write to nn after loop
}
