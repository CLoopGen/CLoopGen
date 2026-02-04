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
    if (uy < 0)
        uy += h;
    if (vy < 0)
        vy += h;
    uint16_t* su_base = &su[uy * sulinesize];
    uint16_t* sv_base = &sv[vy * svlinesize];
    uint16_t* du_row = du;
    uint16_t* dv_row = dv;
    for (int x = 0; x < w; x++) {
        int ux = (x - cbh) % w;
        int vx = (x - crh) % w;
        if (ux < 0)
            ux += w;
        if (vx < 0)
            vx += w;
        du_row[x] = su_base[ux];
        dv_row[x] = sv_base[vx];
    }
    du += ulinesize;
    dv += vlinesize;
}
}
