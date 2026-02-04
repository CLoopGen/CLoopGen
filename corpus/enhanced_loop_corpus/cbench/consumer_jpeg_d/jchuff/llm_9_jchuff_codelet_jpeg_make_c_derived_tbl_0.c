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
    // Variant 2: Reduced arithmetic operations and simplified control flow with flattened single loop
    int total = 0;
    for (l = 1; l <= 16; l++) {
        total += htbl->bits[l];
    }
    for (i = 0; i < total; ) {
        for (l = 1; l <= 16 && i < total; l++) {
            int count = htbl->bits[l];
            while (count-- > 0 && i < total) {
                huffsize[p + i] = (char)l;
                i++;
            }
        }
    }
    p += total;
}
