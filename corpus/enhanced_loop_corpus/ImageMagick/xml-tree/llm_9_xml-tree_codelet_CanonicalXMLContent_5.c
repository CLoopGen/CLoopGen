#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *p;
extern unsigned char *utf8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char val;
    size_t step = 1;
    for (p = utf8; (val = *p) != '\x00'; p += step) {
        step = 1;
        if (val < 32) {
            if (val != 9 && val != 10 && val != 13) {
                break;
            }
        }
        if ((val & 0xC0) == 0xC0) { // Likely start of multi-byte UTF-8 char
            step = 2; // Skip ahead more aggressively in certain cases
        }
    }
}
