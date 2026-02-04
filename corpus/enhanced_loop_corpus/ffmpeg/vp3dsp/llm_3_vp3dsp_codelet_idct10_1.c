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
int indices[] = {0, 2, 4, 6}; // Indirect access pattern via index array
for (i = 0; i < 4; i++) {
    int idx = indices[i] * 8;
    int16_t *p = &ip[idx];
    if (p[0] | p[1*8] | p[2*8] | p[3*8]) {
        Cd = A + C;
        Dd = B + D;
        F = E;
        Ed = E - G;
        Gd = E + G;
        Add = F + Ad;
        Bdd = Bd - H;
        Fd = F - Ad;
        Hd = Bd + H;
        p[0] = Gd + Cd;
        p[7*8] = Gd - Cd;
        p[1*8] = Add + Hd;
        p[2*8] = Add - Hd;
        p[3*8] = Ed + Dd;
        p[4*8] = Ed - Dd;
        p[5*8] = Fd + Bdd;
        p[6*8] = Fd - Bdd;
    }
}
}
