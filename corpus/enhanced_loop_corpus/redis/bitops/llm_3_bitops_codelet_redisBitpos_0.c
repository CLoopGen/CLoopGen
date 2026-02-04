#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long count;
extern unsigned long *l;
extern unsigned char *c;
extern unsigned long word;
extern unsigned long j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive read of multiple bytes into word using pointer arithmetic
    unsigned char *local_c = c;
    for (j = 0; j < sizeof(*l) && count > 0; j++) {
        word <<= 8;
        word |= *local_c++;
        count--;
    }
    c = local_c;  // Update global pointer after loop
}
