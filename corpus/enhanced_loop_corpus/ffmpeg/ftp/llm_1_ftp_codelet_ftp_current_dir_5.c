#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *res;
extern char *start;
extern char *end;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; res[i] && !end; ++i) {
    if (res[i] == '"') {
        if (!start) {
            start = res + i + 1;
        } else {
            end = res + i;
        }
    }
    // Reduced effective nesting by flattening control logic — no nested conditionals beyond the if-chain
    // This version avoids 'continue' and merges exit conditions into the loop guard
}
}
