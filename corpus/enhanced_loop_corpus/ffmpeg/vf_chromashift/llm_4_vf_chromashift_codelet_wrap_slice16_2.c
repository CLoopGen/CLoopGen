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
extern  uint16_t *su;
extern  uint16_t *sv;
extern uint16_t *du;
extern uint16_t *dv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int y = slice_start; y < slice_end; y++) {
    int uy = (y - cbv) % h;
    int vy = (y - crv) % h;
    uy += (uy < 0) * h;
    vy += (vy < 0) * h;
    for (int x = 0; x < w; x++) {
        int ux = (x - cbh) % w;
        int vx = (x - crh) % w;
        ux += (ux < 0) * w;
        vx += (vx < 0) * w;
        du[x] = su[ux + uy * sulinesize];
        dv[x] = sv[vx + vy * svlinesize];
    }
    du += ulinesize;
    dv += vlinesize;
}
}
