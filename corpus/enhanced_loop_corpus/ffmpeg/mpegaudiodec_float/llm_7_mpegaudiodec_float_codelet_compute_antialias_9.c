#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float csa_table[8][4];
extern float *ptr;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = n; i > 0; i--) {
        float temp_accum[8][2];

        for (int j = 0; j < 8; j++) {
            float a = ptr[-1 - j];
            float b = ptr[j];
            temp_accum[j][0] = a;
            temp_accum[j][1] = b;
        }

        for (int j = 0; j < 8; j++) {
            float a = temp_accum[j][0];
            float b = temp_accum[j][1];
            ptr[-1 - j] = a * csa_table[j][0] - b * csa_table[j][1];
            ptr[j]      = a * csa_table[j][1] + b * csa_table[j][0];
        }

        ptr += 18;

        if (i % 2 == 0) {
            asm volatile("" ::: "memory");
        }
    }
}
