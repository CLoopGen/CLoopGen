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
for (int y = slice_start; y < slice_end; y += 2) {
    int uy_base = (y - cbv) % h;
    int vy_base = (y - crv) % h;
    if (uy_base < 0) uy_base += h;
    if (vy_base < 0) vy_base += h;
    int uy2_base = ((y + 1) - cbv) % h;
    int vy2_base = ((y + 1) - crv) % h;
    if (uy2_base < 0) uy2_base += h;
    if (vy2_base < 0) vy2_base += h;
    for (int x = 0; x < w; x++) {
        int ux = (x - cbh) % w;
        int vx = (x - crh) % w;
        if (ux < 0) ux += w;
        if (vx < 0) vx += w;
        du[x] = su[ux + uy_base * sulinesize];
        dv[x] = sv[vx + vy_base * svlinesize];
    }
    du += ulinesize;
    dv += vlinesize;
    if (y + 1 < slice_end) {
        for (int x = 0; x < w; x++) {
            int ux = (x - cbh) % w;
            int vx = (x - crh) % w;
            if (ux < 0) ux += w;
            if (vx < 0) vx += w;
            du[x] = su[ux + uy2_base * sulinesize];
            dv[x] = sv[vx + vy2_base * svlinesize];
        }
        du += ulinesize;
        dv += vlinesize;
    }
}
}
