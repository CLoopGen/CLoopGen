#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint8_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern HuffEntry *distincts;
extern int size;
extern int i;
extern int nbits[257];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            distincts[i].sym = i;
            distincts[i].len = nbits[i];
            distincts[i+1].sym = i+1;
            distincts[i+1].len = nbits[i+1];
        } else {
            distincts[i].sym = i;
            distincts[i].len = nbits[i];
        }
    }
}
