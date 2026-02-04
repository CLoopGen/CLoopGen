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
    uy = (uy < 0) ? uy + h : uy;
    vy = (vy < 0) ? vy + h : vy;
    int base_u_offset = uy * sulinesize;
    int base_v_offset = vy * svlinesize;
    uint16_t* su_row = su + base_u_offset;
    uint16_t* sv_row = sv + base_v_offset;
    for (int x = 0; x < w; x += 4) {
        int limit = (x + 4 <= w) ? x + 4 : w;
        for (int xx = x; xx < limit; xx++) {
            int ux = (xx - cbh) % w;
            int vx = (xx - crh) % w;
            ux = (ux < 0) ? ux + w : ux;
            vx = (vx < 0) ? vx + w : vx;
            du[xx] = su_row[ux];
            dv[xx] = sv_row[vx];
        }
    }
    du += ulinesize;
    dv += vlinesize;
}
}
