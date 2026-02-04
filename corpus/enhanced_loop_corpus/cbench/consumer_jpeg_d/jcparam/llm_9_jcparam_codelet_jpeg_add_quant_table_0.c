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
for (i = 0; i < 64; i += 2) {
    long temp1 = ((long)basic_table[i] * scale_factor + 50L) / 100L;
    long temp2 = (i + 1 < 64) ? ((long)basic_table[i + 1] * scale_factor + 50L) / 100L : temp1;

    if (temp1 <= 0L) temp1 = 1L;
    if (temp1 > 32767L) temp1 = 32767L;
    if (force_baseline && temp1 > 255L) temp1 = 255L;

    if (temp2 <= 0L) temp2 = 1L;
    if (temp2 > 32767L) temp2 = 32767L;
    if (force_baseline && temp2 > 255L) temp2 = 255L;

    (*qtblptr)->quantval[i] = (UINT16)temp1;
    if (i + 1 < 64)
        (*qtblptr)->quantval[i + 1] = (UINT16)temp2;
}
}
