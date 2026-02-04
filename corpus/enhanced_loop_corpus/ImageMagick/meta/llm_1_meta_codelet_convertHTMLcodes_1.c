#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *s;
extern size_t i;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; (i < 7U) && (s[i] != '\x00'); ) {
        if (s[i] == ';') {
            length = i + 1;
            break;
        }
        i++;  // Flattened logic by removing increment from for-statement header
    }
}
