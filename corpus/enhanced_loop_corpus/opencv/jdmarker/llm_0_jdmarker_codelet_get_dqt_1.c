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
for (INT32 outer = 0; outer < 8; outer++) {
    for (INT32 inner = 0; inner < 8; inner++) {
        INT32 i = outer * 8 + inner;
        quant_ptr->quantval[i] = 1;
    }
}
}
