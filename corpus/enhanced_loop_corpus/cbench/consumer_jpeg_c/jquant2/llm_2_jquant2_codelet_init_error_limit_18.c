#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride
    // Instead of accessing table[in] and table[-in], we use a stride of 2
    for (; in <= 255; in += 2) {
        table[2 * in] = out;
        table[-2 * in] = -out;
    }
}
