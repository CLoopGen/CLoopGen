#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t codetable[128][5];
extern int cb_coef;
extern int i;
extern double sumsum;
extern float buffer[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++) {
        buffer[i] = codetable[cb_coef][i] * sumsum;
        for (int k = 0; k < 1; k++);
    }
}
