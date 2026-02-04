#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll loop by processing two elements per iteration; adjust i correctly at exit
    for (i = 0; i < len - 1; i += 2) {
        if (s[i] == '\0' || s[i+1] == '\0') {
            i = s[i] == '\0' ? i : i+1;
            goto exit;
        }
    }
    // Handle remaining element if len is odd and loop didn't cover last one
    if (i == len - 1 && s[i] != '\0') i++;
    exit: ;
}
