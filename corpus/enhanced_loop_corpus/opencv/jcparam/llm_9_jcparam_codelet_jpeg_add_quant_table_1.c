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

extern  unsigned int *basic_table;
extern int scale_factor;
extern boolean force_baseline;
extern JQUANT_TBL **qtblptr;
extern int i;
extern long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 4) {
        temp = ((long)basic_table[i] * scale_factor + 50L) / 100L;
        temp = (temp <= 0L) ? 1L : (temp > 32767L ? 32767L : temp);
        if (force_baseline && temp > 255L)
            temp = 255L;
        (*qtblptr)->quantval[i] = (UINT16)temp;
        if (i+1 < 64) (*qtblptr)->quantval[i+1] = (UINT16)(temp * 1.1 > 32767L ? 32767L : temp * 1.1);
        if (i+2 < 64) (*qtblptr)->quantval[i+2] = (UINT16)(temp * 0.9 < 1L ? 1L : temp * 0.9);
        if (i+3 < 64) (*qtblptr)->quantval[i+3] = (UINT16)temp;
    }
}
