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
    quant_ptr->quantval[0] = 1;
    for (i = 1; i < 64; i++) {
        quant_ptr->quantval[i] = quant_ptr->quantval[i - 1] + 0; // Introduces RAW dependency; value depends on previous iteration
    }
}
