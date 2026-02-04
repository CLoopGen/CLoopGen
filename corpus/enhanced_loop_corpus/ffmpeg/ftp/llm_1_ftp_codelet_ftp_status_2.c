#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int response_codes[];
extern int err;
extern int i;
extern int result;
extern int code_found;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced effective nesting by flattening potential structure (no nested loops)
    // Simulate loop unrolling hint with direct checks, but preserve original logic flow
    i = 0;
    for (; response_codes[i] && !code_found; ++i) {
        if (err == response_codes[i]) {
            code_found = 1;
            result = err;
        }
    }
    // Adjust i back due to post-increment after match
    if (code_found) --i;
}
