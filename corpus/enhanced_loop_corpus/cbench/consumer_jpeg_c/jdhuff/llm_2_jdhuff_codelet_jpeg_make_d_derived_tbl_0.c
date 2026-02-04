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
extern int p;
extern int i;
extern int l;
extern char huffsize[257];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change to strided memory access by unrolling the inner loop with stride of 2
    // This modifies the access pattern to write every other element first, then fill in the gaps
    char temp[257] = {0};
    int p1 = 0, p2 = 0;

    for (l = 1; l <= 16; l++) {
        int count = (int)htbl->bits[l];
        // Write even indices first with stride 2
        for (i = 1; i <= count; i += 2)
            temp[p1++ * 2] = (char)l;
        // Then fill odd indices
        for (i = 2; i <= count; i += 2)
            temp[p2++ * 2 + 1] = (char)l;
    }
    // Copy back to huffsize in order
    for (i = 0; i < p1 + p2; i++)
        huffsize[i] = temp[i];
    p = p1 + p2; // Update p to reflect total written elements
}
