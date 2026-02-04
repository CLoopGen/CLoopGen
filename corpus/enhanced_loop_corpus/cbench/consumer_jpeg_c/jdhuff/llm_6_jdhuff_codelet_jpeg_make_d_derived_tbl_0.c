#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UINT8;

typedef int boolean;

typedef struct {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL;

extern JHUFF_TBL *htbl;
extern int p;
extern int i;
extern int l;
extern char huffsize[257];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Eliminate loop-carried dependency on p by precomputing write indices
    // Introduce a temporary array to remove the WAW and WAR hazards on shared variable 'p'
    char temp_huffsize[257];
    int temp_p = 0;

    for (l = 1; l <= 16; l++) {
        int count = (int)htbl->bits[l];
        for (i = 1; i <= count; i++) {
            temp_huffsize[temp_p++] = (char)l;
        }
    }

    // Copy back to original array and update global p
    for (i = 0; i < temp_p; i++) {
        huffsize[i] = temp_huffsize[i];
    }
    p = temp_p;
}
