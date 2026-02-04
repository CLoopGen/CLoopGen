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
for (i = 1; i <= 16; i++) {
    nb = bits_table[i];
    int base_index = k;
    for (j = 0; j < nb; j++) {
        sym = val_table[base_index + j];
        if (sym != 0 || huff_size[sym] == 0) {
            huff_size[sym] = i;
            huff_code[sym] = code + j;
        }
    }
    k += nb;
    code = (code + nb) << 1;
}
}
