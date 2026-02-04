#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *ip;
extern int A;
extern int B;
extern int C;
extern int D;
extern int Ad;
extern int Bd;
extern int Cd;
extern int Dd;
extern int E;
extern int F;
extern int G;
extern int H;
extern int Ed;
extern int Gd;
extern int Add;
extern int Bdd;
extern int Fd;
extern int Hd;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    if (!(ip[0 * 8] | ip[1 * 8] | ip[2 * 8] | ip[3 * 8] | ip[4 * 8] | ip[5 * 8] | ip[6 * 8] | ip[7 * 8])) {
        ip += 1;
        continue;
    }
    int temp1 = A + C;
    int temp2 = B + D;
    int temp3 = E - G;
    int temp4 = E + G;
    int temp5 = F + Ad;
    int temp6 = Bd - H;
    int temp7 = F - Ad;
    int temp8 = Bd + H;
    ip[0 * 8] = temp4 + temp1;
    ip[7 * 8] = temp4 - temp1;
    ip[1 * 8] = temp5 + temp8;
    ip[2 * 8] = temp5 - temp8;
    ip[3 * 8] = temp3 + temp2;
    ip[4 * 8] = temp3 - temp2;
    ip[5 * 8] = temp7 + temp6;
    ip[6 * 8] = temp7 - temp6;
    ip += 1;
}
}
