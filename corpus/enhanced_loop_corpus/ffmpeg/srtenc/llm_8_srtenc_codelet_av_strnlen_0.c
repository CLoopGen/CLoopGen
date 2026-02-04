#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    if (len > 0) {
        for (; i < len; i += 2) {
            if (!s[i]) break;
            if (i + 1 < len && !s[i + 1]) {
                i++;
                break;
            }
        }
        // Ensure we don't miss the first null byte when stepping by 2
        while (i > 0 && s[i]) i--; // Adjust back to actual null or valid index
        for (; i < len && s[i]; i++);
    }
}
