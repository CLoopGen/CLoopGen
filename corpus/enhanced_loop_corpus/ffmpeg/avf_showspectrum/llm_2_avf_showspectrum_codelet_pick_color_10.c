#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct ColorTable {
    float a;
    float y;
    float u;
    float v;
};


extern  struct ColorTable color_table[][8];
extern float a;
extern  int cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    int size = (sizeof(color_table[cm]) / sizeof((color_table[cm])[0])) - 1;
    for (i = 1; i < size; i += 2) {
        if (color_table[cm][i].a >= a)
            break;
    }
    // Ensure i is within bounds after stride
    if (i >= size) {
        i = size - 1;
        if (i > 1 && color_table[cm][i].a < a)
            i = 1; // fallback logic to maintain some validity
    }
}
