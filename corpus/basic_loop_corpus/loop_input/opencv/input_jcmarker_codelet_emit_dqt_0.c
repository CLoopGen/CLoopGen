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

JQUANT_TBL *qtbl;
int prec;
int i;

void init_vars() {
    qtbl = (JQUANT_TBL*)malloc(sizeof(JQUANT_TBL));
    if (!qtbl) {
        exit(1);
    }
    for (int idx = 0; idx < 64; idx++) {
        qtbl->quantval[idx] = (idx % 2 == 0) ? 300 : 100;
    }
    qtbl->sent_table = 0;
    prec = 0;
    i = 0;
}