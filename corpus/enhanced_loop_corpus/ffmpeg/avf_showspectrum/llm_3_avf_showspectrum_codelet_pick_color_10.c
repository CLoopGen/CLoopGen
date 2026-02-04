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
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    int size = (sizeof(color_table[cm]) / sizeof((color_table[cm])[0])) - 1;
    int indices[8]; // assuming max size is 8 as per [][8]
    for (int j = 0; j < size; j++) {
        indices[j] = j + 1; // indirect indices starting from 1
    }
    for (int j = 0; j < size; j++) {
        i = indices[j];
        if (color_table[cm][i].a >= a)
            break;
    }
}
