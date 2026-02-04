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
    for (i = 0; i < 128; i++) {
        if (i < 64) {
            quant_ptr->quantval[i] = ((i * i + 3 * i + 2) / 2) % 256 + 1;
        }
    }
}
