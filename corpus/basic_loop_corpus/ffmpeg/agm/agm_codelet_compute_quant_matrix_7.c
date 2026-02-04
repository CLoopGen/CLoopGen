#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int luma[64];
extern int chroma[64];
extern double f;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < 64; i++) {
    luma[i] = ((1) > (16 * f) ? (1) : (16 * f));
    chroma[i] = ((1) > (16 * f) ? (1) : (16 * f));
}

}
