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
        if (!s[i]) break;  // Move condition inside loop body, removing combined condition in for-header
        // Introduce artificial RAW dependency: current iteration depends on previous s[i-1] (if exists)
        if (i > 0 && s[i-1] == 0) break;
    }
}
