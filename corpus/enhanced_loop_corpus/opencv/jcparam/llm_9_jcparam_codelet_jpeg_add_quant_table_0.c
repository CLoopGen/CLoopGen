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
long temp1, temp2, temp3, temp4;
for (i = 0; i < 64; i += 4) {
    temp1 = ((long)basic_table[i]     * scale_factor + 50L) / 100L;
    temp2 = ((long)basic_table[i + 1] * scale_factor + 50L) / 100L;
    temp3 = ((long)basic_table[i + 2] * scale_factor + 50L) / 100L;
    temp4 = ((long)basic_table[i + 3] * scale_factor + 50L) / 100L;

    temp1 = (temp1 <= 0L) ? 1L : (temp1 > 32767L) ? 32767L : (force_baseline && temp1 > 255L) ? 255L : temp1;
    temp2 = (temp2 <= 0L) ? 1L : (temp2 > 32767L) ? 32767L : (force_baseline && temp2 > 255L) ? 255L : temp2;
    temp3 = (temp3 <= 0L) ? 1L : (temp3 > 32767L) ? 32767L : (force_baseline && temp3 > 255L) ? 255L : temp3;
    temp4 = (temp4 <= 0L) ? 1L : (temp4 > 32767L) ? 32767L : (force_baseline && temp4 > 255L) ? 255L : temp4;

    (*qtblptr)->quantval[i]     = (UINT16)temp1;
    (*qtblptr)->quantval[i+1]   = (UINT16)temp2;
    (*qtblptr)->quantval[i+2]   = (UINT16)temp3;
    (*qtblptr)->quantval[i+3]   = (UINT16)temp4;
}
}
