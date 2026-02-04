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
    // Variant 2: Memory Access Pattern Modification - Indirect access using precomputed value list
    char values[256];
    int count = 0;
    int l, i;
    for (l = 1; l <= 16; l++) {
        UINT8 bit_count = htbl->bits[l];
        for (i = 1; i <= (int)bit_count; i++) {
            values[count++] = (char)l;
        }
    }
    // Now write indirectly through values array
    for (i = 0; i < count; i++) {
        huffsize[p++] = values[i];
    }
}
