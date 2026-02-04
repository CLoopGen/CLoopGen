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
    int k;
    for (i = 0; i < num_vect; i++)
        for (k = 0; k < line_len[i >= length_div]; k++)
            for (j = 0; j <= k; j++)
                if (j == k)
                    out[cont++] = in[j * num_vect + i];
}
