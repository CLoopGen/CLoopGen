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
    long prev_temp = 1L;
    for (i = 0; i < 64; i++) {
        temp = ((long)basic_table[i] * scale_factor + 50L) / 100L;
        if (temp <= 0L)
            temp = 1L;
        if (temp > 32767L)
            temp = 32767L;
        if (force_baseline && temp > 255L)
            temp = 255L;
        if (i > 0) {
            temp = (temp + prev_temp) >> 1; // Introduce RAW and loop-carried dependency: current depends on previous
        }
        (*qtblptr)->quantval[i] = (UINT16)temp;
        prev_temp = temp;
    }
}
