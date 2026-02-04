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
    // Variant 1: Increased computational intensity by unrolling the inner loop and reducing conditional checks
    // This variant assumes that htbl->bits[l] values are small (<=4) to safely unroll.
    for (l = 1; l <= 16; l++) {
        int count = (int)htbl->bits[l];
        int unroll_factor = 4;
        int remainder = count % unroll_factor;
        
        // Unrolled loop for better performance (fewer iterations, more operations per iteration)
        for (i = 0; i < count - remainder; i += unroll_factor) {
            huffsize[p++] = (char)l;
            huffsize[p++] = (char)l;
            huffsize[p++] = (char)l;
            huffsize[p++] = (char)l;
        }
        // Handle remaining iterations
        for (i = 0; i < remainder; i++) {
            huffsize[p++] = (char)l;
        }
    }
}
