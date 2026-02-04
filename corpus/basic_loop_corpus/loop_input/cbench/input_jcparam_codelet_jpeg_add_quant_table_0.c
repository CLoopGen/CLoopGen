#include <stdio.h>
#include <inttypes.h>

typedef int boolean;
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

static unsigned int basic_table_data[64];
static JQUANT_TBL qtbl_instance;
static JQUANT_TBL *qtblptr_instance;

void init_vars() {
    basic_table = basic_table_data;
    scale_factor = 100;
    force_baseline = 0;
    qtblptr = &qtblptr_instance;
    qtblptr_instance = &qtbl_instance;
    qtbl_instance.sent_table = 0;

    for (int i = 0; i < 64; i++) {
        basic_table_data[i] = 100 + i;
        qtbl_instance.quantval[i] = 0;
    }
}