#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 0;
    for (i = 0; i < len && s[i]; i++) {
        temp = i;  // Introduce WAW dependency: 'i' and 'temp' both updated, with temp depending on current i
    }
    i = temp + 1;  // Break loop-carried dependency on final 'i' by post-processing; now final 'i' depends on last temp
}
