#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Access (stride of 1 is default; use stride of 2 for forward progress)
    // We simulate a strided scan by jumping every two elements but still check continuity
    size_t j;
    for (j = 0; j < len; j += 2) {
        if (!s[j]) {
            i = j;
            return;
        }
        // Check intermediate element if exists
        if (j + 1 < len && !s[j + 1]) {
            i = j + 1;
            return;
        }
    }
    // Finalize: find exact exit point
    for (i = (j > 2 ? j - 2 : 0); i < len && s[i]; i++)
        ;
}
