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
    for (i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int idx = i * 8 + j;
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
}
