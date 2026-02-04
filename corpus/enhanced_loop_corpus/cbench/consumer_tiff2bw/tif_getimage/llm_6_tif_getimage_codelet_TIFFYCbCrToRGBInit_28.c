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
    int temp_cr_r, temp_cb_b;
    for (i = 0, x = -128; i < 256; i++, x++) {
        temp_cr_r = (int)((D1 * x + ((int32)(1 << (16 - 1)))) >> 16);
        temp_cb_b = (int)((D3 * x + ((int32)(1 << (16 - 1)))) >> 16);
        ycbcr->Cr_r_tab[i] = temp_cr_r;
        ycbcr->Cb_b_tab[i] = temp_cb_b;
        ycbcr->Cr_g_tab[i] = D2 * x;
        ycbcr->Cb_g_tab[i] = D4 * x + ((int32)(1 << (16 - 1)));
    }
}
