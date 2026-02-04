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
    for (int outer = 0; outer < 8; outer++) {
        for (int inner = 0; inner < 8; inner++) {
            int index = outer * 8 + inner;
            if (qtbl->quantval[index] > 255) {
                prec = 1;
            }
        }
    }
}
