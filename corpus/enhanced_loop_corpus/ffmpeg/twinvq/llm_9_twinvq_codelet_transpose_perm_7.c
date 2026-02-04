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
    for (i = 0; i < num_vect && cont < 4096; i++) {
        int effective_len = line_len[i >= length_div] >> ((i + 1) & 1);
        for (j = 0; j < effective_len; j++) {
            int offset = j * (num_vect + (num_vect >> 2)) + i;
            out[cont++] = (int16_t)((in[offset] + in[offset + 1]) >> 1);
        }
    }
}
