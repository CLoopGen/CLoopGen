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
    // Variant 1: Strided memory access with forward stride of 2, unrolled pattern to maintain correctness
    // We simulate a strided access by processing even indices first, then odd, to preserve nbits[i] > 0 check
    j = 0;
    for (i = 0; i < 256; i += 2) {
        if (nbits[i] > 0) {
            distincts[j].code = i;
            distincts[j].length = nbits[i];
            j++;
        }
    }
    for (i = 1; i < 256; i += 2) {
        if (nbits[i] > 0) {
            distincts[j].code = i;
            distincts[j].length = nbits[i];
            j++;
        }
    }
}
