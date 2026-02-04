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
    for (i = 0; i < 256; i += 2) {
        if (nbits[i] > 0) {
            distincts[j].code = i;
            distincts[j].length = nbits[i];
            j++;
        }
        if (i + 1 < 256 && nbits[i + 1] > 0) {
            distincts[j].code = i + 1;
            distincts[j].length = nbits[i + 1];
            j++;
        }
    }
}
