#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const char *whitespace = " \t\n\r\f";
    size_t i;
    for (i = 0; i < 5; i++) {
        if ((*type) == whitespace[i]) {
            type++;
            i = -1; // Reset to re-check from beginning after incrementing type
        }
    }
}
