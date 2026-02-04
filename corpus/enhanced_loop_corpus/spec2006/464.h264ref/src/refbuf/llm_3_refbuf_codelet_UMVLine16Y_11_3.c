#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int width;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2) with bounds check
    int stride = 2;
    int start = (((width) > (x)) ? (width) : (x));
    for (i = start; i < maxx; i += stride)
        if ((i - x) < 16)  // Ensure within bounds of line[16]
            line[i - x] = Picy[width - 1];
}
