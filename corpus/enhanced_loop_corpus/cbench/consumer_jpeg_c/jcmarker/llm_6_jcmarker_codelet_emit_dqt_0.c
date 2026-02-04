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
    int temp_prec = 0;
    for (i = 0; i < 64; i++) {
        if (qtbl->quantval[i] > 255) {
            temp_prec = 1;
        }
    }
    prec = temp_prec;
}
