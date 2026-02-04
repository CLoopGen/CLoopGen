#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length;
extern size_t info_length;
extern size_t tag_length;
extern unsigned char *p;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Array-like Access using offset indexing
    size_t base_offset = 0;
    for (i = 0; i < 4; i++) {
        if (length == 0) break;
        tag_length <<= 8;
        tag_length |= p[base_offset];  // Direct consecutive access
        base_offset++;
        length--;
        info_length++;
    }
    p += base_offset;  // Update pointer after loop
}
