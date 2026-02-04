#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char UINT8;
typedef int boolean;

typedef struct {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL;

JHUFF_TBL *htbl;
int codesize[257];
int p;
int i;
int j;

void init_vars() {
    // Allocate and initialize htbl
    htbl = (JHUFF_TBL*)malloc(sizeof(JHUFF_TBL));
    if (!htbl) return;
    
    memset(htbl->bits, 0, sizeof(htbl->bits));
    memset(htbl->huffval, 0, sizeof(htbl->huffval));
    htbl->sent_table = 0;
    
    // Initialize codesize array to create meaningful distribution
    // Set up a pattern where values from 1 to 32 are distributed across the array
    // This ensures the inner loop condition triggers appropriately
    for (int idx = 0; idx < 257; idx++) {
        codesize[idx] = (idx % 32) + 1;  // Values from 1 to 32
    }
    
    // Initialize p to 0
    p = 0;
}