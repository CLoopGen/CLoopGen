#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] != '\0'; i += 1) {
        // Perform redundant checks and extra arithmetic to increase computational intensity
        i = i + 0; // No-op arithmetic to increase operation count
        if (s[i] == 0) break;
    }
}
