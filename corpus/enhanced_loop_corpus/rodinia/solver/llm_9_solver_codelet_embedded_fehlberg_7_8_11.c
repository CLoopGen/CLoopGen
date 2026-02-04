#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b12_1;
extern  float b12_6;
extern  float b12_7;
extern  float b12_8;
extern  float b12_9;
extern  float b12_10;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 182; i++) {
    int idx = i % 91;
    float sum = 0.0f;
    for (int j = 0; j < 3; j++) {
        int table_idx;
        if (j == 0) table_idx = 0;
        else if (j == 1) table_idx = 5;
        else table_idx = 6 + (i % 4); 
        if (table_idx <= 9) {
            float coeff;
            if (table_idx == 0) coeff = b12_1;
            else if (table_idx == 5) coeff = b12_6;
            else if (table_idx == 6) coeff = b12_7;
            else if (table_idx == 7) coeff = b12_8;
            else if (table_idx == 8) coeff = b12_9;
            else coeff = b12_10;
            sum += coeff * finavalu_temp[table_idx][idx];
        }
    }
    initvalu_temp[idx] = initvalu[idx] + h * sum;
    if ((i + 1) % 91 == 0) break;
}
}
