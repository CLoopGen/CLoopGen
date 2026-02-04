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
    // Variant 1: Increased computational intensity by unrolling inner loop and reducing condition checks
    // Also increased effective trip count by processing two iterations per step where possible
    for (l = 1; l <= 16; l++) {
        int count = (int)htbl->bits[l];
        while (count >= 2) {
            huffsize[p++] = (char)l;
            huffsize[p++] = (char)l;
            count -= 2;
        }
        if (count == 1) {
            huffsize[p++] = (char)l;
        }
    }
}
