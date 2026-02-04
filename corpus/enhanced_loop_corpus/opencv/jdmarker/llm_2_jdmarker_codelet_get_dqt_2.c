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
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to handle even indices
    for (i = 0; i < 64; i += 2) {
        quant_ptr->quantval[i] = 1;
        if (i + 1 < 64) {
            quant_ptr->quantval[i + 1] = 1;
        }
    }
}
