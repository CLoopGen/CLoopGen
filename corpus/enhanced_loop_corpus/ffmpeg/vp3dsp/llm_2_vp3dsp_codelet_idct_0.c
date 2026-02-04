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
    int16_t *p = ip + i * 8;
    if (p[0] | p[1] | p[2] | p[3] | p[4] | p[5] | p[6] | p[7]) {
        Cd = A + C;
        Dd = B + D;
        Ed = E - G;
        Gd = E + G;
        Add = F + Ad;
        Bdd = Bd - H;
        Fd = F - Ad;
        Hd = Bd + H;
        p[0] = Gd + Cd;
        p[7] = Gd - Cd;
        p[1] = Add + Hd;
        p[2] = Add - Hd;
        p[3] = Ed + Dd;
        p[4] = Ed - Dd;
        p[5] = Fd + Bdd;
        p[6] = Fd - Bdd;
    }
}
}
