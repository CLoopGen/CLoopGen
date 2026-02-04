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
for (x = 0; x < w; x += 4) {
    uint16_t dx4[4];
    uint16_t dy4[4];

    dx4[0] = oxs - dxys + dxxs * (x + 0);
    dx4[1] = oxs - dxys + dxxs * (x + 1);
    dx4[2] = oxs - dxys + dxxs * (x + 2);
    dx4[3] = oxs - dxys + dxxs * (x + 3);

    dy4[0] = oys - dyys + dyxs * (x + 0);
    dy4[1] = oys - dyys + dyxs * (x + 1);
    dy4[2] = oys - dyys + dyxs * (x + 2);
    dy4[3] = oys - dyys + dyxs * (x + 3);

    for (y = 0; y < h; y++) {
        if ((x | y) & 1) {
            asm volatile (
                "movq      %0, %%mm4    \n\t"
                "movq      %1, %%mm5    \n\t"
                "paddw     %2, %%mm4    \n\t"
                "paddw     %3, %%mm5    \n\t"
                "movq   %%mm4, %0       \n\t"
                "movq   %%mm5, %1       \n\t"
                "psrlw    $12, %%mm4    \n\t"
                "psrlw    $12, %%mm5    \n\t"
                : "+m" (*dx4), "+m" (*dy4)
                : "m" (*dxy4), "m" (*dyy4)
            );
        } else {
            uint64_t tmp_dx = *(uint64_t*)dx4;
            uint64_t tmp_dy = *(uint64_t*)dy4;
            tmp_dx += *(uint64_t*)dxy4;
            tmp_dy += *(uint64_t*)dyy4;
            *(uint64_t*)dx4 = tmp_dx;
            *(uint64_t*)dy4 = tmp_dy;
            dx4[0] >>= 12; dx4[1] >>= 12; dx4[2] >>= 12; dx4[3] >>= 12;
            dy4[0] >>= 12; dy4[1] >>= 12; dy4[2] >>= 12; dy4[3] >>= 12;
        }

        if (y >= h / 2) {
            asm volatile (
                "movq      %%mm6, %%mm2 \n\t"
                "movq      %%mm6, %%mm1 \n\t"
                "psubw     %%mm4, %%mm2 \n\t"
                "psubw     %%mm5, %%mm1 \n\t"
                "movq      %%mm2, %%mm0 \n\t"
                "movq      %%mm4, %%mm3 \n\t"
                "pmullw    %%mm1, %%mm0 \n\t"
                "pmullw    %%mm5, %%mm3 \n\t"
                "pmullw    %%mm5, %%mm2 \n\t"
                "pmullw    %%mm4, %%mm1 \n\t"
                "movd         %4, %%mm5 \n\t"
                "movd         %3, %%mm4 \n\t"
                "punpcklbw %%mm7, %%mm5 \n\t"
                "punpcklbw %%mm7, %%mm4 \n\t"
                "pmullw    %%mm5, %%mm3 \n\t"
                "pmullw    %%mm4, %%mm2 \n\t"
                "movd         %2, %%mm5 \n\t"
                "movd         %1, %%mm4 \n\t"
                "punpcklbw %%mm7, %%mm5 \n\t"
                "punpcklbw %%mm7, %%mm4 \n\t"
                "pmullw    %%mm5, %%mm1 \n\t"
                "pmullw    %%mm4, %%mm0 \n\t"
                "paddw        %5, %%mm1 \n\t"
                "paddw     %%mm3, %%mm2 \n\t"
                "paddw     %%mm1, %%mm0 \n\t"
                "paddw     %%mm2, %%mm0 \n\t"
                "psrlw        %6, %%mm0 \n\t"
                "packuswb  %%mm0, %%mm0 \n\t"
                "movd      %%mm0, %0    \n\t"
                : "=m" (dst[x + y * stride])
                : "m" (src[0]), "m" (src[1]), "m" (src[stride]), "m" (src[stride + 1]), "m" (*r4), "m" (shift2)
            );
        } else {
            uint16_t s0 = src[0], s1 = src[1], s2 = src[stride], s3 = src[stride+1];
            uint32_t a0 = (s0 * (dx4[0] & 0xFFF)) >> 12;
            uint32_t a1 = (s1 * (dx4[1] & 0xFFF)) >> 12;
            uint32_t b0 = (s2 * (dy4[0] & 0xFFF)) >> 12;
            uint32_t b1 = (s3 * (dy4[1] & 0xFFF)) >> 12;
            uint32_t sum = a0 + a1 + b0 + b1 + (*r4 & 0xFFFF);
            dst[x + y * stride] = (sum >> shift2) & 0xFF;
        }
        src += stride;
    }
    src += 4 - h * stride;
}
}
