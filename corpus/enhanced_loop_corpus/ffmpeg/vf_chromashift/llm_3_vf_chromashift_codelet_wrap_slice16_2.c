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
    int uy = ((y - cbv) % h + h) % h;
    int vy = ((y - crv) % h + h) % h;
    uint16_t* du_row = du;
    uint16_t* dv_row = dv;
    for (int x = 0; x < w; x += 2) {
        int ux0 = ((x     - cbh) % w + w) % w;
        int ux1 = ((x + 1 - cbh) % w + w) % w;
        int vx0 = ((x     - crh) % w + w) % w;
        int vx1 = ((x + 1 - crh) % w + w) % w;
        du_row[x    ] = su[ux0 + uy * sulinesize];
        dv_row[x    ] = sv[vx0 + vy * svlinesize];
        if (x + 1 < w) {
            du_row[x + 1] = su[ux1 + uy * sulinesize];
            dv_row[x + 1] = sv[vx1 + vy * svlinesize];
        }
    }
    du += ulinesize;
    dv += vlinesize;
}
}
