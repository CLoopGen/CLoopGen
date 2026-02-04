#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char val;
    for (i = 0; i < len; i++) {
        val = s[i];          // Introduce temporary to create RAW dependency within the iteration
        if (!val) break;     // Move condition check after load to enforce read-before-exit semantic
        // Loop-carried dependency on 'i' remains, but data flow now includes explicit use of loaded value before loop exit
    }
}
