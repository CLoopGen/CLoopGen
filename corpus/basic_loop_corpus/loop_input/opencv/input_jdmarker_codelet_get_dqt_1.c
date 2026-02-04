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

INT32 i;
JQUANT_TBL *quant_ptr;

void init_vars() {
    quant_ptr = (JQUANT_TBL*)malloc(sizeof(JQUANT_TBL));
    if (!quant_ptr) {
        exit(1);
    }
    quant_ptr->sent_table = 0;
}