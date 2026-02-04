#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern u_int dim;
extern int i;
extern double *b_ent;
extern double *out_ent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int j;
    double temp = 0.0;
    for (i = dim - 1; i >= 0; i--) {
        if (b_ent[i] != 0.) {
            temp = b_ent[i];
            break;
        } else {
            out_ent[i] = 0.;
            temp = out_ent[i]; // Introduce WAW and WAR dependency via temp
        }
    }
    // Use temp post-loop to preserve semantic relevance
    if (temp == 0.0 && i < 0)
        out_ent[0] = 1.0; // Handle edge case without altering core logic
}
