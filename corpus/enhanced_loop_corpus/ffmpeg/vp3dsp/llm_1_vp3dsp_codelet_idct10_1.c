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
for (i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        if (ip[0 * 8] | ip[1 * 8] | ip[2 * 8] | ip[3 * 8]) {
            Cd = A + C;
            Dd = B + D;
            F = E;
            Ed = E - G;
            Gd = E + G;
            Add = F + Ad;
            Bdd = Bd - H;
            Fd = F - Ad;
            Hd = Bd + H;
            ip[0 * 8] = Gd + Cd;
            ip[7 * 8] = Gd - Cd;
            ip[1 * 8] = Add + Hd;
            ip[2 * 8] = Add - Hd;
            ip[3 * 8] = Ed + Dd;
            ip[4 * 8] = Ed - Dd;
            ip[5 * 8] = Fd + Bdd;
            ip[6 * 8] = Fd - Bdd;
        }
        ip += 1;
    }
}
}
