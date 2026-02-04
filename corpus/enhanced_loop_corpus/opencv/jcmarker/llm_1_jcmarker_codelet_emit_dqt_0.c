#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
    for (i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int idx = i * 8 + j;
            if (qtbl->quantval[idx] > 255)
                prec = 1;
        }
    }
}
