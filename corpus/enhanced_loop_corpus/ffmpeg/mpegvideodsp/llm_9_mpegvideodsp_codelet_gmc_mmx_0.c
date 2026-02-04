#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int stride;
extern int h;
extern  int w;
extern  int oxs;
extern  int oys;
extern  int dxxs;
extern  int dxys;
extern  int dyxs;
extern  int dyys;
extern  uint16_t r4[4];
extern  uint16_t dxy4[4];
extern  uint16_t dyy4[4];
extern  uint64_t shift2;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < w; x += 8) {
    uint16_t dx4[8];
    uint16_t dy4[8];
    for (int i = 0; i < 8; ++i) {
        dx4[i] = oxs - dxys + dxxs * (x + i);
        dy4[i] = oys - dyys + dyxs * (x + i);
    }
    for (y = 0; y < h; y += 2) {
        for (int j = 0; j < 8; j += 4) {
            asm volatile ("movq      %0, %%mm4    \n\tmovq      %1, %%mm5    \n\tpaddw     %2, %%mm4    \n\tpaddw     %3, %%mm5    \n\tmovq   %%mm4, %0       \n\tmovq   %%mm5, %1       \n\tpsrlw    $12, %%mm4    \n\tpsrlw    $12, %%mm5    \n\t"
                          : "+m" (dx4[j]), "+m" (dy4[j]) : "m" (*dxy4), "m" (*dyy4));
            asm volatile ("movq      %%mm6, %%mm2 \n\tmovq      %%mm6, %%mm1 \n\tpsubw     %%mm4, %%mm2 \n\tpsubw     %%mm5, %%mm1 \n\tmovq      %%mm2, %%mm0 \n\tmovq      %%mm4, %%mm3 \n\tpmullw    %%mm1, %%mm0 \n\tpmullw    %%mm5, %%mm3 \n\tpmullw    %%mm5, %%mm2 \n\tpmullw    %%mm4, %%mm1 \n\tmovd         %4, %%mm5 \n\tmovd         %3, %%mm4 \n\tpunpcklbw %%mm7, %%mm5 \n\tpunpcklbw %%mm7, %%mm4 \n\tpmullw    %%mm5, %%mm3 \n\tpmullw    %%mm4, %%mm2 \n\tmovd         %2, %%mm5 \n\tmovd         %1, %%mm4 \n\tpunpcklbw %%mm7, %%mm5 \n\tpunpcklbw %%mm7, %%mm4 \n\tpmullw    %%mm5, %%mm1 \n\tpmullw    %%mm4, %%mm0 \n\tpaddw        %5, %%mm1 \n\tpaddw     %%mm3, %%mm2 \n\tpaddw     %%mm1, %%mm0 \n\tpaddw     %%mm2, %%mm0 \n\tpsrlw        %6, %%mm0 \n\tpackuswb  %%mm0, %%mm0 \n\tmovd      %%mm0, %0    \n\t"
                          : "=m" (dst[(x+j) + y * stride]) : "m" (src[0]), "m" (src[1]), "m" (src[stride]), "m" (src[stride+1]), "m" (*r4), "m" (shift2));
            if (y + 1 < h) {
                asm volatile ("movq      %%mm6, %%mm2 \n\tmovq      %%mm6, %%mm1 \n\tpsubw     %%mm4, %%mm2 \n\tpsubw     %%mm5, %%mm1 \n\tmovq      %%mm2, %%mm0 \n\tmovq      %%mm4, %%mm3 \n\tpmullw    %%mm1, %%mm0 \n\tpmullw    %%mm5, %%mm3 \n\tpmullw    %%mm5, %%mm2 \n\tpmullw    %%mm4, %%mm1 \n\tmovd         %4, %%mm5 \n\tmovd         %3, %%mm4 \n\tpunpcklbw %%mm7, %%mm5 \n\tpunpcklbw %%mm7, %%mm4 \n\tpmullw    %%mm5, %%mm3 \n\tpmullw    %%mm4, %%mm2 \n\tmovd         %2, %%mm5 \n\tmovd         %1, %%mm4 \n\tpunpcklbw %%mm7, %%mm5 \n\tpunpcklbw %%mm7, %%mm4 \n\tpmullw    %%mm5, %%mm1 \n\tpmullw    %%mm4, %%mm0 \n\tpaddw        %5, %%mm1 \n\tpaddw     %%mm3, %%mm2 \n\tpaddw     %%mm1, %%mm0 \n\tpaddw     %%mm2, %%mm0 \n\tpsrlw        %6, %%mm0 \n\tpackuswb  %%mm0, %%mm0 \n\tmovd      %%mm0, %0    \n\t"
                              : "=m" (dst[(x+j) + (y+1) * stride]) : "m" (src[stride*2]), "m" (src[stride*2+1]), "m" (src[stride*3]), "m" (src[stride*3+1]), "m" (*r4), "m" (shift2));
            }
        }
        src += 2 * stride;
    }
    src += 8 - h * stride;
}
}
