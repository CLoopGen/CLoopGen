#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing stride
    // Access elements using a stride of 2 to create non-unit strided access
    int stride = 2;
    for (i = 2; i < (6 + 3) - 1; i++)
        *(p - stride * i) = *(x - stride * i);
}
