#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern unsigned char lowervec[256];
extern int patlen;
extern int skip2;
extern uchar *pat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing step size (triangular access pattern)
    // Simulate irregular strided access by varying the index progression
    int step = 1;
    for (i = 0; i < patlen - 1; i += step) {
        int current_index = i % (patlen - 1); // Wrap-around to stay within bounds

        if (lowervec[(uchar)(pat[current_index])] == lowervec[(uchar)(pat[patlen - 1])])
            skip2 = patlen - current_index - 1;

        step = (step % 8) + 1; // Cycle step size between 1 and 8 for variable stride
    }
}
