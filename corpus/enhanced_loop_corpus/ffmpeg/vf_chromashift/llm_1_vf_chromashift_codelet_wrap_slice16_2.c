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
int total_pixels = w * (slice_end - slice_start);
for (int idx = 0; idx < total_pixels; idx++) {
    int y = slice_start + idx / w;
    int x = idx % w;

    int uy = (y - cbv) % h;
    int vy = (y - crv) % h;
    if (uy < 0) uy += h;
    if (vy < 0) vy += h;

    int ux = (x - cbh) % w;
    int vx = (x - crh) % w;
    if (ux < 0) ux += w;
    if (vx < 0) vx += w;

    int dest_offset = idx;
    int su_offset = ux + uy * sulinesize;
    int sv_offset = vx + vy * svlinesize;

    ((uint16_t*)du)[dest_offset] = su[su_offset];
    ((uint16_t*)dv)[dest_offset] = sv[sv_offset];
}
}
