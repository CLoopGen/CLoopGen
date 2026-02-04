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
    // Variant 2: Strided memory access with stride of 2, processing even indices first, then odd
    int stride = 2;
    int phase;

    for (phase = 0; phase < 2; phase++) {
        for (i = phase; i < 64; i += stride) {
            temp = ((long)basic_table[i] * scale_factor + 50L) / 100L;
            if (temp <= 0L)
                temp = 1L;
            if (temp > 32767L)
                temp = 32767L;
            if (force_baseline && temp > 255L)
                temp = 255L;
            (*qtblptr)->quantval[i] = (UINT16)temp;
        }
    }
}
