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
    int prev_length = 0;
    for (i = 0; i < nval; i++) {
        val[i] = distincts[i].code;
        bits[distincts[i].length]++;
        if (i > 0) {
            bits[prev_length] += (distincts[i].length == prev_length) ? 1 : 0;
        }
        prev_length = distincts[i].length;
    }
}
