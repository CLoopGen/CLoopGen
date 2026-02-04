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
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to handle even and odd indices separately
    prec = 0; // Reset prec in case no element exceeds 255
    for (i = 0; i < 64; i += 2) {
        if (qtbl->quantval[i] > 255) {
            prec = 1;
            break;
        }
    }
    if (!prec) {
        for (i = 1; i < 64; i += 2) {
            if (qtbl->quantval[i] > 255) {
                prec = 1;
                break;
            }
        }
    }
}
