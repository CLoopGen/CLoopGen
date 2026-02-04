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

extern  unsigned int *basic_table;
extern int scale_factor;
extern boolean force_baseline;
extern JQUANT_TBL **qtblptr;
extern int i;
extern long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Mapping (use a fixed permutation table to access elements)
    static const int index_map[64] = {
        0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30,
        32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62,
        1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31,
        33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63
    };
    for (i = 0; i < 64; i++) {
        int idx = index_map[i];
        temp = ((long)basic_table[idx] * scale_factor + 50L) / 100L;
        if (temp <= 0L)
            temp = 1L;
        if (temp > 32767L)
            temp = 32767L;
        if (force_baseline && temp > 255L)
            temp = 255L;
        (*qtblptr)->quantval[idx] = (UINT16)temp;
    }
}
