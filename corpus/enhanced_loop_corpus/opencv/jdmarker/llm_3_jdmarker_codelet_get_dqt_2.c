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
    // Variant 2: Reverse consecutive memory access — traverse array from last to first element
    for (i = 63; i >= 0; i--) {
        quant_ptr->quantval[i] = 1;
    }
}
