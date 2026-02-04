#include <stdio.h>

#include <inttypes.h>

extern  char *vPtr;
extern char buffer[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 1, but accessed in reverse via index scaling)
    int stride = 1;
    for (i = 0; i < sizeof(float); i += stride) {
        buffer[i] = vPtr[(sizeof(float) - 1) - (i * stride)];
    }
}
