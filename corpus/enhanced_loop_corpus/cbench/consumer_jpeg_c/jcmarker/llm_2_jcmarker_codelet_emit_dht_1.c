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
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every second element in reverse order, then handle remainder)
    int stride = 2;
    // First pass: strided access from high to low indices
    for (i = 16; i >= 1; i -= stride) {
        length += htbl->bits[i];
    }
    // Second pass: handle the odd indices if starting from even offset
    for (i = 15; i >= 1; i -= stride) {
        length += htbl->bits[i];
    }
}
