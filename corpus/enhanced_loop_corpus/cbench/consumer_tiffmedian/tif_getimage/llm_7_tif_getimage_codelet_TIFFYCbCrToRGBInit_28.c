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
    for (i = 0, x = -128; i < 256; i++, x++) {
        int32 scaled_x = x << 8;
        ycbcr->Cr_r_tab[i] = (int)((D1 * scaled_x + ((int32)(1 << (23)))) >> 24);
        ycbcr->Cr_g_tab[i] = D2 * scaled_x >> 8;
        ycbcr->Cb_b_tab[i] = (int)((D3 * scaled_x + ((int32)(1 << (23)))) >> 24);
        ycbcr->Cb_g_tab[i] = (D4 * scaled_x >> 8) + ((int32)(1 << 15));
    }
}
