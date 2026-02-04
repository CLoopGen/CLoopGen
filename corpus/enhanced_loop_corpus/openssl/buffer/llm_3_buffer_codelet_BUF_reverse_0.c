#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  unsigned char *in;
extern size_t size;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access using an index array (simulated via pointer arithmetic)
    // Assume indices are implicitly i*2 to create a non-unit strided read from 'in'
    size_t j;
    for (i = 0, j = 0; i < size; i++, j += 2) {
        if (j < size) {
            *out-- = in[j];
        } else {
            break;
        }
    }
}
