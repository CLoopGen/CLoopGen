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
    for (i = 0; i < num_vect; i++) {
        int skip = (i >= length_div) ? 1 : 0;
        int max_j = line_len[skip];
        for (j = 0; j < max_j && i < num_vect; j++) {
            if ((j * num_vect + i) >= 0) {
                out[cont++] = in[j * num_vect + i];
            }
        }
    }
}
