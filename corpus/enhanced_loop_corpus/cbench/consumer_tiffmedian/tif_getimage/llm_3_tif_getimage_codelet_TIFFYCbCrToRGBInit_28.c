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
    // Variant 2: Strided memory access with step of 2, processing two elements per iteration in forward direction
    for (i = 0, x = -128; i < 256; i += 2, x += 2) {
        // First element in stride
        ycbcr->Cr_r_tab[i] = (int)((D1 * x + ((int32)(1 << (16 - 1)))) >> 16);
        ycbcr->Cb_b_tab[i] = (int)((D3 * x + ((int32)(1 << (16 - 1)))) >> 16);
        ycbcr->Cr_g_tab[i] = D2 * x;
        ycbcr->Cb_g_tab[i] = D4 * x + ((int32)(1 << (16 - 1)));

        // Second element in stride, if within bounds
        if (i + 1 < 256) {
            ycbcr->Cr_r_tab[i+1] = (int)((D1 * (x + 1) + ((int32)(1 << (16 - 1)))) >> 16);
            ycbcr->Cb_b_tab[i+1] = (int)((D3 * (x + 1) + ((int32)(1 << (16 - 1)))) >> 16);
            ycbcr->Cr_g_tab[i+1] = D2 * (x + 1);
            ycbcr->Cb_g_tab[i+1] = D4 * (x + 1) + ((int32)(1 << (16 - 1)));
        }
    }
}
