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
    for (int stride = 0; stride < 64; stride += 16) {
        for (int i = stride; i < stride + 16 && i < 64; i++) {
            if (qtbl->quantval[i] > 255)
                prec = 1;
        }
    }
}
