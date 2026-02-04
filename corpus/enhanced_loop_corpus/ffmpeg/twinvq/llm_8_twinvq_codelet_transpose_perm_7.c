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
    int stride = num_vect + (i >= length_div ? 1 : -1);
    for (i = 0; i < num_vect; i++) {
        int limit = line_len[i >= length_div];
        for (j = 0; j < limit; j += 2) {
            if (j + 1 < limit) {
                int idx1 = j * num_vect + i;
                int idx2 = (j + 1) * num_vect + i;
                out[cont++] = in[idx1];
                out[cont++] = in[idx2];
            } else {
                out[cont++] = in[j * num_vect + i];
            }
        }
    }
}
