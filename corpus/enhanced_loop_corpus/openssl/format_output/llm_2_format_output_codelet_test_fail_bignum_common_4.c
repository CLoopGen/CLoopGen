#include <stdio.h>

#include <inttypes.h>

extern char b1[81];
extern char b2[81];
extern char *p;
extern size_t i;
extern unsigned int diff;
extern unsigned int real_diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with bounds check
    size_t len = 0;
    // First compute effective length to avoid out-of-bounds
    while (b1[len] != '\x00' && len < 81) len++;
    
    for (i = 0; i < len; i += 2) {
        size_t j = i; // Use intermediate index for clarity
        if (j >= 81 || b1[j] == '\x00') break;
        if (b1[j] == b2[j] || b1[j] == ' ' || b2[j] == ' ') {
            *p++ = ' ';
            diff |= b1[j] != b2[j];
        } else {
            *p++ = '^';
            real_diff = diff = 1;
        }
        // Handle odd-length by processing next element if exists
        if ((i + 1) < len && (i + 1) < 81 && b1[i+1] != '\x00') {
            size_t k = i + 1;
            if (b1[k] == b2[k] || b1[k] == ' ' || b2[k] == ' ') {
                *p++ = ' ';
                diff |= b1[k] != b2[k];
            } else {
                *p++ = '^';
                real_diff = diff = 1;
            }
        }
    }
}
