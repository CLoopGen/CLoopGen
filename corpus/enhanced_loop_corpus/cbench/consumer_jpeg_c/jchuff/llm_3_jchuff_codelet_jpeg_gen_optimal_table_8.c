#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UINT8;

typedef int boolean;

typedef struct {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL;

extern JHUFF_TBL *htbl;
extern int codesize[257];
extern int p;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed outer loop and indirect indexing
    // Outer loop now counts down, inner loop uses a fixed stride to access codesize in non-linear order
    p = p; // preserve starting point
    for (i = 32; i >= 1; i--) {
        // Stride of 4 through j values to create strided memory access pattern
        for (j = 0; j <= 255; j += 4) {
            // Check unrolled elements within stride to maintain correctness
            if (j <= 255 && codesize[j] == i) {
                htbl->huffval[p] = (UINT8)j;
                p++;
            }
            if (j+1 <= 255 && codesize[j+1] == i) {
                htbl->huffval[p] = (UINT8)(j+1);
                p++;
            }
            if (j+2 <= 255 && codesize[j+2] == i) {
                htbl->huffval[p] = (UINT8)(j+2);
                p++;
            }
            if (j+3 <= 255 && codesize[j+3] == i) {
                htbl->huffval[p] = (UINT8)(j+3);
                p++;
            }
        }
    }
}
