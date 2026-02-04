#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        if (!s[i]) {
            break;
        }
        // Removed direct loop-carried data dependency in the condition by moving the null check inside.
        // Original combined condition split: eliminates potential dual evaluation side effects,
        // and restructures control flow while preserving semantics.
        // This variant weakens the original AND-constrained exit, making it two-tiered.
    }
}
