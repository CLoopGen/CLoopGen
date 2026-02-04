#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via calculated indices)
    int indices[256];
    for (int j = 0; j < 256; ++j) {
        indices[j] = 255 - j; // reverse order access
    }
    for (i = 0; i < 256; ++i) {
        table[indices[i]] = (JSAMPLE)indices[i];
    }
}
