#include <stdio.h>

#include <inttypes.h>

extern size_t *len;
extern size_t i;
extern  uint8_t *ptr;
extern int found;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2 instead of 1)
    // This changes the access pattern to jump two elements at a time
    // Adjust logic to prevent out-of-bounds when checking i+1
    for (i = 0; i + 1 < *len; i += 2) {
        if (*ptr == 255 && *(ptr + 1) == 255) {
            ptr++;
            found = 1;
            break;
        }
        ptr += 2;
    }
    // Handle remaining element if *len is odd and no match found yet
    if (!found && i < *len) {
        ptr++;
    }
}
