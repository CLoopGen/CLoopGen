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
int *indices = (int*)alloca(16 * sizeof(int));
for (int idx = 0; idx < 16; idx++) {
    indices[idx] = idx + 1;
}
for (int iter = 0; iter < 16; iter++) {
    i = indices[iter];
    nb = bits_table[i];
    for (j = 0; j < nb; j++) {
        int access_idx = k++;
        sym = val_table[access_idx];
        int cond = (sym != 0 || huff_size[sym] == 0);
        if (cond) {
            huff_size[sym] = i;
            huff_code[sym] = code;
        }
        code++;
    }
    code <<= 1;
}
}
