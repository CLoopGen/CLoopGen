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
    if (size > 0) {
        i = 0;
        for (int block = 0; block < size; block += 1) {
            distincts[i].sym = i;
            distincts[i].len = nbits[i];
            i++;
        }
    }
}
