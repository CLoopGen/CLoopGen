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
INT32 stride = 4;
for (INT32 block = 0; block < 64; block += stride) {
    for (INT32 offset = 0; offset < stride && (block + offset) < 64; offset++) {
        INT32 i = block + offset;
        quant_ptr->quantval[i] = 1;
    }
}
}
