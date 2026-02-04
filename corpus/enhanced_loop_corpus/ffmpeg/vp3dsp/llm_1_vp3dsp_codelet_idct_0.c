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
        for (int j = 0; j < 4; j++) {
            int idx = j * 2;
            if (ip[idx * 8] | ip[(idx+1) * 8]) {
                Cd = A + C;
                Dd = B + D;
                Ed = E - G;
                Gd = E + G;
                Add = F + Ad;
                Bdd = Bd - H;
                Fd = F - Ad;
                Hd = Bd + H;
                ip[idx * 8]     = Gd + Cd;
                ip[(idx+1) * 8] = Gd - Cd;
                ip[(idx+2) * 8] = Add + Hd;
                ip[(idx+3) * 8] = Add - Hd;
                ip[(idx+4) * 8] = Ed + Dd;
                ip[(idx+5) * 8] = Ed - Dd;
                ip[(idx+6) * 8] = Fd + Bdd;
                ip[(idx+7) * 8] = Fd - Bdd;
            }
            ip += 2;
        }
    }
}
