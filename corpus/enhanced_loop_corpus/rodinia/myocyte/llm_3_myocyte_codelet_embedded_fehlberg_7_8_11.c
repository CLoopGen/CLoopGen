#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern  float b11_1;
extern  float b11_4;
extern  float b11_5;
extern  float b11_6;
extern  float b11_7;
extern  float b11_8;
extern  float b11_9;
extern  float b11_10;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int access_pattern[91];
for (int k = 0; k < 91; k++) {
    access_pattern[k] = (73 * k + 17) % 91; // Linear congruential shuffle for indirect access
}
for (i = 0; i < 91; i++) {
    int idx = access_pattern[i];
    initvalu_temp[idx] = initvalu[idx] + h * (b11_1 * finavalu_temp[0][idx] + b11_4 * finavalu_temp[3][idx] + 
                                              b11_5 * finavalu_temp[4][idx] + b11_6 * finavalu_temp[5][idx] + 
                                              b11_7 * finavalu_temp[6][idx] + b11_8 * finavalu_temp[7][idx] + 
                                              b11_9 * finavalu_temp[8][idx] + b11_10 * finavalu_temp[9][idx]);
}
}
