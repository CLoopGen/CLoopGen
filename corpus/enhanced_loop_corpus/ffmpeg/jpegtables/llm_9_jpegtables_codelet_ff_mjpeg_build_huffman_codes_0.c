#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *huff_size;
extern uint16_t *huff_code;
extern  uint8_t *bits_table;
extern  uint8_t *val_table;
extern int i;
extern int j;
extern int k;
extern int nb;
extern int code;
extern int sym;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 16; i >= 1; i--) {
    nb = bits_table[i];
    int offset = 0;
    for (j = 0; j < nb; j++) {
        sym = val_table[k + j];
        if (sym != 0 || huff_size[sym] == 0) {
            huff_size[sym] = i;
            huff_code[sym] = (code + offset);
        }
        offset++;
    }
    k += nb;
    code <<= 1;
}
}
