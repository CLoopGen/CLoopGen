#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int sulinesize;
extern  int svlinesize;
extern  int ulinesize;
extern  int vlinesize;
extern  int cbh;
extern  int cbv;
extern  int crh;
extern  int crv;
extern  int h;
extern  int w;
extern  int slice_start;
extern  int slice_end;
extern  uint8_t *su;
extern  uint8_t *sv;
extern uint8_t *du;
extern uint8_t *dv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int y = slice_start;
for (; y < slice_end; y++) {
    int uy = (y - cbv) % h;
    int vy = (y - crv) % h;
    if (uy < 0) uy += h;
    if (vy < 0) vy += h;
    int offset_u = uy * sulinesize;
    int offset_v = vy * svlinesize;
    for (int x = 0; x < w; x++) {
        int ux = (x - cbh + w) % w;
        int vx = (x - crh + w) % w;
        du[x] = su[ux + offset_u];
        dv[x] = sv[vx + offset_v];
    }
    du += ulinesize;
    dv += vlinesize;
}
}
