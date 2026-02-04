#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced iterations with step of 2, but verify all characters via internal check
    for (i = 0; i < len; i += 2) {
        if (!s[i]) break;
        if (i + 1 < len && !s[i + 1]) {
            i++;
            break;
        }
    }
    // Final linear scan from i onward to maintain correctness
    for (; i < len && s[i]; i++)
        ;
}
