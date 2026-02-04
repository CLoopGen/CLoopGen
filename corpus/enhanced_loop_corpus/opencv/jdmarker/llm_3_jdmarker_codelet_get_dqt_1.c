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
    // Variant 2: Indirect memory access using a fixed index mapping (reverse order traversal)
    for (i = 0; i < 64; i++) {
        INT32 idx = 63 - i;  // reverse access: from last to first
        quant_ptr->quantval[idx] = 1;
    }
}
