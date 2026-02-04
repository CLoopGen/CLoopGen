#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffTable {
    int code;
    int length;
} HuffTable;

extern HuffTable *distincts;
extern int i;
extern int j;
extern int nbits[257];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i++) {
        int idx = i >> 1;
        if (idx < 256 && nbits[idx] > 0 && (i % 2 == 0)) {
            distincts[j].code = idx;
            distincts[j].length = nbits[idx];
            j++;
        }
    }
}
