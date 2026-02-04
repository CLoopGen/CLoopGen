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
    // Variant 2: Indirect memory access using an index mapping array (simulating non-sequential access)
    static const int index_map[64] = {
        0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30,
        1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31,
        32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62,
        33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63
    };
    prec = 0;
    for (i = 0; i < 64; i++) {
        int idx = index_map[i];
        if (qtbl->quantval[idx] > 255) {
            prec = 1;
            break;
        }
    }
}
