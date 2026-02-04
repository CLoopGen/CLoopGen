#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (access every 2nd element)
    for (; in < ((255 + 1) / 16) * 3; in++, out += (in & 1) ? 0 : 1) {
        int stride = 2;
        table[in * stride] = out;
        table[-(in * stride)] = -out;
    }
}
