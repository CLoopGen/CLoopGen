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
for (i = 0; i < 16; i++) {
    if (ip[0 * 8] | ip[1 * 8] | ip[2 * 8] | ip[3 * 8] | ip[4 * 8] | ip[5 * 8] | ip[6 * 8] | ip[7 * 8]) {
        Cd = A + C;
        Dd = B + D;
        Ed = E - G;
        Gd = E + G;
        Add = F + Ad;
        Bdd = Bd - H;
        Fd = F - Ad;
        Hd = Bd + H;
        int temp1 = Gd + Cd;
        int temp2 = Gd - Cd;
        int temp3 = Add + Hd;
        int temp4 = Add - Hd;
        int temp5 = Ed + Dd;
        int temp6 = Ed - Dd;
        int temp7 = Fd + Bdd;
        int temp8 = Fd - Bdd;
        ip[0 * 8] = temp1;
        ip[7 * 8] = temp2;
        ip[1 * 8] = temp3;
        ip[2 * 8] = temp4;
        ip[3 * 8] = temp5;
        ip[4 * 8] = temp6;
        ip[5 * 8] = temp7;
        ip[6 * 8] = temp8;
    }
    ip += 1;
}
}
