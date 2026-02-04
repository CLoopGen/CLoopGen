#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float h;
extern float *initvalu;
extern float *finavalu;
extern  float c_1_11;
extern  float c6;
extern  float c_7_8;
extern  float c_9_10;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 91; i += 7) {
    int j1 = i;
    int j2 = (i + 1) % 91;
    int j3 = (i + 2) % 91;
    int j4 = (i + 3) % 91;
    int j5 = (i + 4) % 91;
    int j6 = (i + 5) % 91;
    int j7 = (i + 6) % 91;
    
    finavalu[j1] = initvalu[j1] + h * (c_1_11 * (finavalu_temp[0][j1] + finavalu_temp[10][j1]) + c6 * finavalu_temp[5][j1] + c_7_8 * (finavalu_temp[6][j1] + finavalu_temp[7][j1]) + c_9_10 * (finavalu_temp[8][j1] + finavalu_temp[9][j1]));
    if (j2 < 91) finavalu[j2] = initvalu[j2] + h * (c_1_11 * (finavalu_temp[0][j2] + finavalu_temp[10][j2]) + c6 * finavalu_temp[5][j2] + c_7_8 * (finavalu_temp[6][j2] + finavalu_temp[7][j2]) + c_9_10 * (finavalu_temp[8][j2] + finavalu_temp[9][j2]));
    if (j3 < 91) finavalu[j3] = initvalu[j3] + h * (c_1_11 * (finavalu_temp[0][j3] + finavalu_temp[10][j3]) + c6 * finavalu_temp[5][j3] + c_7_8 * (finavalu_temp[6][j3] + finavalu_temp[7][j3]) + c_9_10 * (finavalu_temp[8][j3] + finavalu_temp[9][j3]));
    if (j4 < 91) finavalu[j4] = initvalu[j4] + h * (c_1_11 * (finavalu_temp[0][j4] + finavalu_temp[10][j4]) + c6 * finavalu_temp[5][j4] + c_7_8 * (finavalu_temp[6][j4] + finavalu_temp[7][j4]) + c_9_10 * (finavalu_temp[8][j4] + finavalu_temp[9][j4]));
    if (j5 < 91) finavalu[j5] = initvalu[j5] + h * (c_1_11 * (finavalu_temp[0][j5] + finavalu_temp[10][j5]) + c6 * finavalu_temp[5][j5] + c_7_8 * (finavalu_temp[6][j5] + finavalu_temp[7][j5]) + c_9_10 * (finavalu_temp[8][j5] + finavalu_temp[9][j5]));
    if (j6 < 91) finavalu[j6] = initvalu[j6] + h * (c_1_11 * (finavalu_temp[0][j6] + finavalu_temp[10][j6]) + c6 * finavalu_temp[5][j6] + c_7_8 * (finavalu_temp[6][j6] + finavalu_temp[7][j6]) + c_9_10 * (finavalu_temp[8][j6] + finavalu_temp[9][j6]));
    if (j7 < 91) finavalu[j7] = initvalu[j7] + h * (c_1_11 * (finavalu_temp[0][j7] + finavalu_temp[10][j7]) + c6 * finavalu_temp[5][j7] + c_7_8 * (finavalu_temp[6][j7] + finavalu_temp[7][j7]) + c_9_10 * (finavalu_temp[8][j7] + finavalu_temp[9][j7]));
}
}
