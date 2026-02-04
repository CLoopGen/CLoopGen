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
    for (i = 0; i < num_vect && line_len[i >= length_div] > 0; i++) {
        j = 0;
        for (; j < line_len[i >= length_div]; ) {
            out[cont++] = in[j * num_vect + i];
            j++;
        }
    }
}
