#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j = 0;
    for (i = 0; j < len && s[j]; j++, i++) {
        // Convert to use separate induction variable j; breaks RAW dependency of i in condition
        // Loop still increments i, but uses j for indexing and bounds check
    }
    // Final value of i equals j due to parallel increment
}
