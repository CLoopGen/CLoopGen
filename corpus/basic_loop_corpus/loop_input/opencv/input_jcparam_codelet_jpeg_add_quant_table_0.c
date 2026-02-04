#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char boolean;
typedef unsigned short UINT16;

typedef struct {
    UINT16 quantval[64];
    boolean sent_table;
} JQUANT_TBL;

unsigned int *basic_table;
int scale_factor;
boolean force_baseline;
JQUANT_TBL **qtblptr;
int i;
long temp;

JQUANT_TBL qtbl_instance = {{0}, 0};
JQUANT_TBL *qtblptr_instance = &qtbl_instance;
unsigned int basic_table_data[64];

void init_vars() {
    basic_table = basic_table_data;
    scale_factor = 100;
    force_baseline = 0;

    for (int j = 0; j < 64; j++) {
        basic_table[j] = 100 + j;
    }

    qtblptr = &qtblptr_instance;
}