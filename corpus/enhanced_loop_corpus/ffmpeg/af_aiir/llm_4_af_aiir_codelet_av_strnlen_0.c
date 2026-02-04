#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided forward traversal with step size 2, then cleanup
    size_t step;
    for (i = 0; i < len; i += 2) {
        if (s[i] == '\0') {
            i--; // Adjust so next loop starts at correct position
            break;
        }
        if (i + 1 < len && s[i + 1] == '\0') {
            i++;
            break;
        }
    }
    // Sequential continuation from adjusted i
    for (; i < len && s[i]; i++)
        ;
}
