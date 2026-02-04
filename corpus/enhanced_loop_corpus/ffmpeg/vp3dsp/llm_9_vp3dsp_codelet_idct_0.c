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
    int offset1 = (0 * 8), offset2 = (1 * 8), offset3 = (2 * 8), offset4 = (3 * 8);
    int offset5 = (4 * 8), offset6 = (5 * 8), offset7 = (6 * 8), offset8 = (7 * 8);
    if (ip[offset1] | ip[offset2] | ip[offset3] | ip[offset4] | ip[offset5] | ip[offset6] | ip[offset7] | ip[offset8]) {
        Cd = A + C;
        Dd = B + D;
        Ed = E - G;
        Gd = E + G;
        Add = F + Ad;
        Bdd = Bd - H;
        Fd = F - Ad;
        Hd = Bd + H;
        ip[offset1] = (Gd + Cd) >> 1;
        ip[offset8] = (Gd - Cd) >> 1;
        ip[offset2] = (Add + Hd) >> 1;
        ip[offset3] = (Add - Hd) >> 1;
        ip[offset4] = (Ed + Dd) >> 1;
        ip[offset5] = (Ed - Dd) >> 1;
        ip[offset6] = (Fd + Bdd) >> 1;
        ip[offset7] = (Fd - Bdd) >> 1;
    }
    ip += 2;
}
}
