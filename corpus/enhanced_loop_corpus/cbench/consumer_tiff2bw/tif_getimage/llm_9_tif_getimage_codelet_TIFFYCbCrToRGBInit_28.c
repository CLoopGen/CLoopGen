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
for (i = 0; i < 256; i += 2) {
    int x1 = i - 128;
    int x2 = i - 127;
    
    ycbcr->Cr_r_tab[i]     = (int)((D1 * x1 + ((int32)(1 << 16))) >> 16);
    ycbcr->Cb_b_tab[i]     = (int)((D3 * x1 + ((int32)(1 << 16))) >> 16);
    ycbcr->Cr_g_tab[i]     = D2 * x1;
    ycbcr->Cb_g_tab[i]     = D4 * x1 + ((int32)(1 << 16));
    
    if (i + 1 < 256) {
        ycbcr->Cr_r_tab[i+1] = (int)((D1 * x2 + ((int32)(1 << 16))) >> 16);
        ycbcr->Cb_b_tab[i+1] = (int)((D3 * x2 + ((int32)(1 << 16))) >> 16);
        ycbcr->Cr_g_tab[i+1] = D2 * x2;
        ycbcr->Cb_g_tab[i+1] = D4 * x2 + ((int32)(1 << 16));
    }
}
}
