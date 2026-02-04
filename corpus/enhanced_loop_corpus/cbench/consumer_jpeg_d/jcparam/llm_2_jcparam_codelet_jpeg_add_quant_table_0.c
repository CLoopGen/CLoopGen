#include <stdio.h>

#include <inttypes.h>

typedef int boolean;

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
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    for (i = 0; i < 64; i += 2) {
        int idx0 = i;
        int idx1 = i + 1;

        // Process first element
        temp = ((long)basic_table[idx0] * scale_factor + 50L) / 100L;
        if (temp <= 0L)
            temp = 1L;
        if (temp > 32767L)
            temp = 32767L;
        if (force_baseline && temp > 255L)
            temp = 255L;
        (*qtblptr)->quantval[idx0] = (UINT16)temp;

        // Process second element if within bounds
        if (idx1 < 64) {
            temp = ((long)basic_table[idx1] * scale_factor + 50L) / 100L;
            if (temp <= 0L)
                temp = 1L;
            if (temp > 32767L)
                temp = 32767L;
            if (force_baseline && temp > 255L)
                temp = 255L;
            (*qtblptr)->quantval[idx1] = (UINT16)temp;
        }
    }
}
