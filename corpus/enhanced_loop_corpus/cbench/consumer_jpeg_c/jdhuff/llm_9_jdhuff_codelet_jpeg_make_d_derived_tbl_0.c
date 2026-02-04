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
    // Variant 2: Reduced computational intensity by merging outer and inner logic into a single loop
    // with precomputed bounds, minimizing nested control flow and arithmetic overhead
    int total = 0;
    for (l = 1; l <= 16; l++) {
        total += (int)htbl->bits[l];
    }
    for (i = 0; i < total; ) {
        for (l = 1; l <= 16 && i < total; l++) {
            int count = (int)htbl->bits[l];
            for (int j = 0; j < count && i < total; j++) {
                huffsize[p + i] = (char)l;
                i++;
            }
        }
    }
    p += total;
}
