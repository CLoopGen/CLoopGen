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
for (i = 0; i < 256; i++) {
    if (nbits[i] > 0) {
        distincts[j].code = i;
        distincts[j].length = nbits[i];
        j++;
    }
}

}
