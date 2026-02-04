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
            break;  // Remove potential loop-carried data dependency by restructuring condition; still preserves termination on null char
        }
    }
    // Semantics equivalent: loop exits when either i reaches len or s[i] is '\0'
}
