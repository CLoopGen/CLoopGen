#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 16; ii++) {
    float temp0 = *(a01 + 0);
    float temp1 = *(a01 + 1);
    float temp2 = *(a01 + 2);
    float temp3 = *(a01 + 3);
    float temp4 = *(a01 + 4);
    float temp5 = *(a01 + 5);
    float temp6 = *(a01 + 6);
    float temp7 = *(a01 + 7);
    float temp8 = *(a01 + 8);
    float temp9 = *(a01 + 9);
    float temp10 = *(a01 + 10);
    float temp11 = *(a01 + 11);
    float temp12 = *(a01 + 12);
    float temp13 = *(a01 + 13);
    float temp14 = *(a01 + 14);
    float temp15 = *(a01 + 15);
    float temp16 = *(a01 + 16);
    float temp17 = *(a01 + 17);
    float temp18 = *(a01 + 18);
    float temp19 = *(a01 + 19);
    float temp20 = *(a01 + 20);
    float temp21 = *(a01 + 21);
    float temp22 = *(a01 + 22);
    float temp23 = *(a01 + 23);
    float temp24 = *(a01 + 24);
    float temp25 = *(a01 + 25);
    float temp26 = *(a01 + 26);
    float temp27 = *(a01 + 27);
    float temp28 = *(a01 + 28);
    float temp29 = *(a01 + 29);
    float temp30 = *(a01 + 30);
    float temp31 = *(a01 + 31);

    b[0] = temp0;
    b[1] = temp1;
    b[2] = temp2;
    b[3] = temp3;
    b[4] = temp4;
    b[5] = temp5;
    b[6] = temp6;
    b[7] = temp7;
    b[8] = temp8;
    b[9] = temp9;
    b[10] = temp10;
    b[11] = temp11;
    b[12] = temp12;
    b[13] = temp13;
    b[14] = temp14;
    b[15] = temp15;
    b[16] = temp16;
    b[17] = temp17;
    b[18] = temp18;
    b[19] = temp19;
    b[20] = temp20;
    b[21] = temp21;
    b[22] = temp22;
    b[23] = temp23;
    b[24] = temp24;
    b[25] = temp25;
    b[26] = temp26;
    b[27] = temp27;
    b[28] = temp28;
    b[29] = temp29;
    b[30] = temp30;
    b[31] = temp31;

    a01 += lda;
    b += 32;
}
}
