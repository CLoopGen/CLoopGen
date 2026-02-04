#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef unsigned short UINT16;

typedef unsigned char boolean;

typedef struct {
    UINT16 quantval[64];
    boolean sent_table;
} JQUANT_TBL;

extern INT32 i;
extern JQUANT_TBL *quant_ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count via unrolling
    for (i = 0; i < 64; i += 4) {
        quant_ptr->quantval[i]     = (1 + i) * 2;
        quant_ptr->quantval[i + 1] = (1 + i + 1) * 2;
        quant_ptr->quantval[i + 2] = (1 + i + 2) * 2;
        quant_ptr->quantval[i + 3] = (1 + i + 3) * 2;
    }
}
