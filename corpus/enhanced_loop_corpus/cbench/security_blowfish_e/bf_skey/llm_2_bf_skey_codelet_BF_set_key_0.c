#include <stdio.h>

#include <inttypes.h>

extern unsigned char *data;
extern int i;
extern unsigned long *p;
extern unsigned long ri;
extern unsigned char *d;
extern unsigned char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pre-increment and manual index scaling
    unsigned char *temp_d = d;
    for (i = 0; i < (16 + 2); i++) {
        ri = 0;
        // Read 4 bytes consecutively using direct indexing with modulo-based wraparound
        for (int j = 0; j < 4; j++) {
            unsigned char byte = (temp_d >= end) ? *(data + ((temp_d - data) % (end - data))) : *temp_d;
            ri = (ri << 8) | byte;
            temp_d++;
        }
        p[i] ^= ri;
    }
    d = temp_d;
}
