#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *keyword;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element, but adjust logic to still check 8 bounds)
    for (i = 0; i < 8 && ptr8[i] != ' '; i += 2) {
        keyword[i] = ptr8[i];
        if (i + 1 < 8 && ptr8[i + 1] != ' ') {
            keyword[i + 1] = ptr8[i + 1];
        }
    }
}
