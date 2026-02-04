#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned short UINT16;
typedef int boolean;

typedef struct {
    UINT16 quantval[64];
    boolean sent_table;
} JQUANT_TBL;

JQUANT_TBL *qtbl;
int prec;
int i;

void init_vars() {
    qtbl = (JQUANT_TBL*)malloc(sizeof(JQUANT_TBL));
    if (qtbl == NULL) {
        // Handle allocation failure, though no error handling allowed per instructions
        return;
    }
    for (int idx = 0; idx < 64; idx++) {
        qtbl->quantval[idx] = (idx % 2) ? 300 : 100; // Ensure some values > 255 to trigger prec = 1
    }
    qtbl->sent_table = 0;
    prec = 0;
    i = 0;
}