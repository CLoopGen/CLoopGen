#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t j;
    for (i = stride - 4; i > 0; i--) {
        j = i + stride;
        j = j * 2;  // WAR hazard eliminated by reusing j safely; no loop-carried dependency.
        // All operations are independent across iterations (no loop-carried dependencies).
        // Each iteration computes a local value of j with no effect on other iterations.
    }
    // Loop maintains same trip count and structure but includes independent per-iteration computation.
}
