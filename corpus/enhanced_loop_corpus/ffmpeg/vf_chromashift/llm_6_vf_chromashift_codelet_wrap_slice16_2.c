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
    int base_uy = uy * sulinesize;
    int base_vy = vy * svlinesize;
    for (int x = 0; x < w; x++) {
        int ux = (x - cbh) % w;
        int vx = (x - crh) % w;
        if (ux < 0)
            ux += w;
        if (vx < 0)
            vx += w;
        uint16_t temp_su = su[ux + base_uy];
        uint16_t temp_sv = sv[vx + base_vy];
        du[x] = temp_su;
        dv[x] = temp_sv;
    }
    du += ulinesize;
    dv += vlinesize;
}
}
