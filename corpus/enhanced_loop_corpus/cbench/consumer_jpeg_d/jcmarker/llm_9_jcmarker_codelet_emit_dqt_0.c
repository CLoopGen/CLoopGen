#include <stdio.h>

#include <inttypes.h>

typedef unsigned short UINT16;

typedef int boolean;

typedef struct {
    UINT16 quantval[64];
    boolean sent_table;
} JQUANT_TBL;

extern JQUANT_TBL *qtbl;
extern int prec;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        UINT16 val = qtbl->quantval[i];
        if ((val > 255) && ((val & 1) == 1)) {
            prec = 1;
        }
        prec = (val > 511) ? 1 : prec;
    }
}
