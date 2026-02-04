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
    long temp_arr[64];
    for (i = 0; i < 64; i++) {
        temp_arr[i] = ((long)basic_table[i] * scale_factor + 50L) / 100L;
        if (temp_arr[i] <= 0L)
            temp_arr[i] = 1L;
        if (temp_arr[i] > 32767L)
            temp_arr[i] = 32767L;
        if (force_baseline && temp_arr[i] > 255L)
            temp_arr[i] = 255L;
    }
    for (i = 0; i < 64; i++) {
        (*qtblptr)->quantval[i] = (UINT16)temp_arr[i];
    }
}
