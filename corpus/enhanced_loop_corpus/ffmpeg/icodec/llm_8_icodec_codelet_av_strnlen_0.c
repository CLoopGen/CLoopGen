#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided access with step 2, then fix-up
    size_t step = 2;
    for (i = 0; i + step - 1 < len; i += step) {
        if (!s[i] || !s[i + 1]) {
            i -= (s[i]) ? 1 : 0;
            break;
        }
    }
    for (; i < len && s[i]; i++);
}
