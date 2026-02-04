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
for (i = 0; i < 4; i++) {
    int16_t *base = ip + i; // Consecutive base pointer offset
    if (base[0] | base[8] | base[16] | base[24]) {
        Cd = A + C;
        Dd = B + D;
        F = E;
        Ed = E - G;
        Gd = E + G;
        Add = F + Ad;
        Bdd = Bd - H;
        Fd = F - Ad;
        Hd = Bd + H;
        base[0] = Gd + Cd;
        base[56] = Gd - Cd;
        base[8] = Add + Hd;
        base[16] = Add - Hd;
        base[24] = Ed + Dd;
        base[32] = Ed - Dd;
        base[40] = Fd + Bdd;
        base[48] = Fd - Bdd;
    }
}
}
