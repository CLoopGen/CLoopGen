#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (process every 2nd byte starting from index 0)
    size_t i;
    for (i = 0; &content[i] < p + 1 && content[i] != '\x00'; i += 2) {
        length += (content[i] & 128) != 0 ? 2 : 1;
    }
}
