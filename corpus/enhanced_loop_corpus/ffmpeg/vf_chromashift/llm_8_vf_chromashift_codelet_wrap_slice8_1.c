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
for (int y = slice_start; y < slice_end; y += 2) {
    int uy_base = (y - cbv) % h;
    int vy_base = (y - crv) % h;
    if (uy_base < 0) uy_base += h;
    if (vy_base < 0) vy_base += h;
    int uy_next = (y + 1 - cbv) % h;
    int vy_next = (y + 1 - crv) % h;
    if (uy_next < 0) uy_next += h;
    if (vy_next < 0) vy_next += h;
    for (int x = 0; x < w; x++) {
        int ux = (x - cbh) % w;
        int vx = (x - crh) % w;
        if (ux < 0) ux += w;
        if (vx < 0) vx += w;
        int idx_u = ux + uy_base * sulinesize;
        int idx_v = vx + vy_base * svlinesize;
        du[x] = su[idx_u];
        dv[x] = sv[idx_v];
    }
    du += ulinesize;
    dv += vlinesize;
    if (y + 1 < slice_end) {
        for (int x = 0; x < w; x++) {
            int ux = (x - cbh) % w;
            int vx = (x - crh) % w;
            if (ux < 0) ux += w;
            if (vx < 0) vx += w;
            int idx_u = ux + uy_next * sulinesize;
            int idx_v = vx + vy_next * svlinesize;
            du[x] = su[idx_u];
            dv[x] = sv[idx_v];
        }
        du += ulinesize;
        dv += vlinesize;
    }
}
}
