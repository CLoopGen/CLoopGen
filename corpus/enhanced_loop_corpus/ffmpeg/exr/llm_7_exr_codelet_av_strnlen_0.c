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
        // Eliminated the combined condition check in the loop header
        // Introduced early exit via break, removing loop-carried WAW hazard on termination condition
        // Data dependency is now strictly linear on 'i', with no overlapping write-check in guard
    }
}
