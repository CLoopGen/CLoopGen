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
    for (int outer = 0; outer < 16; outer++) {
        for (int inner = 0; inner < 16; inner++) {
            int idx = outer * 16 + inner;
            if (nbits[idx] > 0) {
                distincts[j].code = idx;
                distincts[j].length = nbits[idx];
                j++;
            }
        }
    }
}
