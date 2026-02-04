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
for (int y = slice_start; y < slice_end; y++) {
    int uy = (y - cbv) % h;
    int vy = (y - crv) % h;
    if (uy < 0)
        uy += h;
    if (vy < 0)
        vy += h;
    int temp_uy_offset = uy * sulinesize;
    int temp_vy_offset = vy * svlinesize;
    for (int x = 0; x < w; x++) {
        int ux = (x - cbh) % w;
        int vx = (x - crh) % w;
        if (ux < 0)
            ux += w;
        if (vx < 0)
            vx += w;
        uint8_t temp_su_val = su[ux + temp_uy_offset];
        uint8_t temp_sv_val = sv[vx + temp_vy_offset];
        du[x] = temp_su_val;
        dv[x] = temp_sv_val;
    }
    du += ulinesize;
    dv += vlinesize;
}
}
