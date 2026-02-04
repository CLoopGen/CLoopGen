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
for (i = 0; i < 64; i++) {
    temp = ((long)basic_table[i] * scale_factor + 50L) / 100L;
    temp = (temp <= 0L) ? 1L : temp;
    temp = (force_baseline && temp > 255L) ? 255L : temp;
    temp = (temp > 32767L) ? 32767L : temp;
    (*qtblptr)->quantval[i] = (UINT16)temp;
}
}
