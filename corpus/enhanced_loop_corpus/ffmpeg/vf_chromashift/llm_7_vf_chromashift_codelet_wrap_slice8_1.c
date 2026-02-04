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
uint8_t* local_du = du;
uint8_t* local_dv = dv;
for (int y = slice_start; y < slice_end; y++) {
    int uy = ((y - cbv) % h + h) % h;
    int vy = ((y - crv) % h + h) % h;
    int base_su_index = uy * sulinesize;
    int base_sv_index = vy * svlinesize;
    for (int x = 0; x < w; x++) {
        int ux = ((x - cbh) % w + w) % w;
        int vx = ((x - crh) % w + w) % w;
        int su_index = base_su_index + ux;
        int sv_index = base_sv_index + vx;
        local_du[x] = su[su_index];
        local_dv[x] = sv[sv_index];
    }
    local_du += ulinesize;
    local_dv += vlinesize;
}
du = local_du;
dv = local_dv;
}
