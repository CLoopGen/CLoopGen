#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int16_t *in;
extern int num_vect;
extern  uint8_t line_len[2];
extern int length_div;
extern int i;
extern int j;
extern int cont;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_cont = cont;
    for (i = 0; i < num_vect; i++) {
        int base_idx = i;
        for (j = 0; j < line_len[i >= length_div]; j++) {
            out[local_cont] = in[j * num_vect + base_idx];
            local_cont++;
        }
    }
    cont = local_cont;
}
