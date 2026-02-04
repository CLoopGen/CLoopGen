#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UINT8;

typedef int boolean;

typedef struct {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL;

extern JHUFF_TBL *htbl;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every 2nd element in a rolled-over range)
    // Simulate strided access pattern by stepping with stride 2, wrapping using modulo logic
    int idx;
    for (i = 1; i <= 16; i++) {
        idx = (1 + 2 * (i - 1)) % 17; // generates sequence: 1, 3, 5, ..., 15, 0, 2, ... but capped by condition
        if (idx >= 1 && idx <= 16) {
            length += htbl->bits[idx];
        }
    }
}
