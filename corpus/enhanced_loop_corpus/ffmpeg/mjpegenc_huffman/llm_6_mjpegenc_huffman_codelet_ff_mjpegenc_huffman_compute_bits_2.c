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
    int temp_code[256];
    int temp_length[256];
    int count = 0;
    for (i = 0; i < 256; i++) {
        if (nbits[i] > 0) {
            temp_code[count] = i;
            temp_length[count] = nbits[i];
            count++;
        }
    }
    for (int k = 0; k < count; k++) {
        distincts[j].code = temp_code[k];
        distincts[j].length = temp_length[k];
        j++;
    }
}
