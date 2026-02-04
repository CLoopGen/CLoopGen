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
    // Variant 1: Consecutive memory access with reverse traversal
    for (i = 255, x = 127; i >= 0; i--, x--) {
        ycbcr->Cr_r_tab[i] = (int)((D1 * x + ((int32)(1 << (16 - 1)))) >> 16);
        ycbcr->Cb_b_tab[i] = (int)((D3 * x + ((int32)(1 << (16 - 1)))) >> 16);
        ycbcr->Cr_g_tab[i] = D2 * x;
        ycbcr->Cb_g_tab[i] = D4 * x + ((int32)(1 << (16 - 1)));
    }
}
