#include <stdio.h>

#include <inttypes.h>

extern size_t table[256];
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step;
    for (i = 0; i < 256; i++) {
        table[i] = len + (i % 4) * (i % 4);
    }
}
