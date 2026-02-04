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
for (i = 0; i < 64; i++) {
    temp = ((long)basic_table[i] * scale_factor + 50L) / 100L;
    boolean clamp_to_1 = (temp <= 0L);
    boolean clamp_to_max = (!clamp_to_1 && temp > 32767L);
    boolean clamp_to_baseline = (!clamp_to_1 && !clamp_to_max && force_baseline && temp > 255L);

    if (clamp_to_1)
        temp = 1L;
    else if (clamp_to_baseline)
        temp = 255L;
    else if (clamp_to_max)
        temp = 32767L;

    (*qtblptr)->quantval[i] = (UINT16)temp;
}
}
