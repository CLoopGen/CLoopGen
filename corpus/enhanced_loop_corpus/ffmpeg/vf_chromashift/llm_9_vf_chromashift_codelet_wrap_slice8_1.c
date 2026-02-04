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
    uy = (uy < 0) ? uy + h : uy;
    vy = (vy < 0) ? vy + h : vy;
    int base_u_offset = uy * sulinesize;
    int base_v_offset = vy * svlinesize;
    uint8_t* su_base = su + base_u_offset;
    uint8_t* sv_base = sv + base_v_offset;
    for (int x = 0; x < w; x += 4) {
        int limit = (x + 4 <= w) ? x + 4 : w;
        for (int x_inner = x; x_inner < limit; x_inner++) {
            int ux = (x_inner - cbh) % w;
            int vx = (x_inner - crh) % w;
            ux = (ux < 0) ? ux + w : ux;
            vx = (vx < 0) ? vx + w : vx;
            du[x_inner] = su_base[ux];
            dv[x_inner] = sv_base[vx];
        }
    }
    du += ulinesize;
    dv += vlinesize;
}
}
