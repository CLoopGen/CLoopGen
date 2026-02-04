#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffTable {
    int code;
    int length;
} HuffTable;

extern uint8_t bits[17];
extern uint8_t val[];
extern int i;
extern int nval;
extern HuffTable distincts[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nval; i++) {
        if (distincts[i].length >= 1 && distincts[i].length <= 16) {
            val[i] = distincts[i].code;
            bits[distincts[i].length]++;
        }
    }
}
