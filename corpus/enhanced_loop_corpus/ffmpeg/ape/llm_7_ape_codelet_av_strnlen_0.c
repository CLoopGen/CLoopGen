#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_len = len;
    for (i = 0; i < temp_len; i++) {
        char c = s[i];
        if (!c) break;
        // Remove direct loop-carried dependency on condition evaluation
        // Introduce RAW: 's[i]' read after 'i' update in prior iteration
        // 'temp_len' breaks dependency on dynamic 'len' modification (if any)
    }
    // Semantics preserved: exits when null terminator or end of buffer reached
}
