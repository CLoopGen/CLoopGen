#include <stdio.h>

#include <inttypes.h>

typedef unsigned char TIFFRGBValue;

typedef int int32;

typedef struct {
    TIFFRGBValue *clamptab;
    int *Cr_r_tab;
    int *Cb_b_tab;
    int32 *Cr_g_tab;
    int32 *Cb_g_tab;
    float coeffs[3];
} TIFFYCbCrToRGB;

extern TIFFYCbCrToRGB *ycbcr;
extern int i;
extern int32 D1;
extern int32 D2;
extern int32 D3;
extern int32 D4;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; i++) {
    int offset = i - 128;
    int32 scaled_x_high = offset << 4;
    int32 temp_cr_g = D2 * offset;
    int32 temp_cb_g = D4 * offset;

    ycbcr->Cr_r_tab[i] = (int)((D1 * scaled_x_high + ((int32)(1 << (19 - 1)))) >> 19);
    ycbcr->Cb_b_tab[i] = (int)((D3 * scaled_x_high + ((int32)(1 << (19 - 1)))) >> 19);
    ycbcr->Cr_g_tab[i] = temp_cr_g;
    ycbcr->Cb_g_tab[i] = temp_cb_g + ((int32)(1 << (18 - 1)));

    // Additional computational work to increase intensity
    ycbcr->Cr_r_tab[i] += (ycbcr->Cr_r_tab[i] >> 4) & 0x0F;
    ycbcr->Cb_b_tab[i] = (ycbcr->Cb_b_tab[i] * 5 + 2) / 7;
}
}
