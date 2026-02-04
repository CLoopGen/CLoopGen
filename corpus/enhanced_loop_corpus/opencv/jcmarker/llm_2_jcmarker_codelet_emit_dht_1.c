#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    UINT8 *bits_ptr = htbl->bits + 1;  // Point to bits[1]
    int count = 16;
    for (i = 1; i <= 16; i++) {
        length += *bits_ptr;
        bits_ptr++;
    }
}
