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
        if (!s[i]) break;
        // Move the array access inside the loop body, eliminating loop-carried data dependency through the condition
        // Original WAW/RAR dependency on 'i' remains, but termination condition no longer carries dependency on 's[i]'
    }
}
