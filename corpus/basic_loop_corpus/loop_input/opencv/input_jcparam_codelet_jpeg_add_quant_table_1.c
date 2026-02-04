#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

JQUANT_TBL *qtbl_storage;
unsigned int basic_table_storage[64];

void init_vars() {
    // Allocate and initialize basic_table as an array of 64 unsigned integers
    for (int idx = 0; idx < 64; idx++) {
        basic_table_storage[idx] = 100 + idx; // Arbitrary non-zero values
    }
    basic_table = basic_table_storage;

    // Initialize scalar variables
    scale_factor = 100;
    force_baseline = 1;

    // Allocate and initialize the JQUANT_TBL instance
    qtbl_storage = (JQUANT_TBL *)calloc(1, sizeof(JQUANT_TBL));
    if (!qtbl_storage) exit(1);

    // Initialize sent_table to 0 (not strictly necessary but safe)
    qtbl_storage->sent_table = 0;

    // Set up double pointer: qtblptr points to qtbl_storage
    qtblptr = &qtbl_storage;

    // Initialize loop index and temp
    i = 0;
    temp = 0;
}