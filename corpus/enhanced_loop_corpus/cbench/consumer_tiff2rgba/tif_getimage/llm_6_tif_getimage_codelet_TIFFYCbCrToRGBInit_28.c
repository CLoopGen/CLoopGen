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
    // Variant 1: Introduce loop-carried WAW dependency by reordering and chaining writes
    // We introduce a write-after-write dependency on Cr_r_tab[i] by splitting the computation
    // and introducing artificial dependence on previous iteration's result.
    int temp = 0;
    for (i = 0, x = -128; i < 256; i++, x++) {
        // Artificially chain Cr_r_tab[i] to depend on prior value (WAW via reuse of temp)
        temp = (int)((D1 * x + ((int32)(1 << (16 - 1)))) >> 16);
        ycbcr->Cr_r_tab[i] = temp + (i > 0 ? ycbcr->Cr_r_tab[i-1] & 0x1 : 0); // introduces loop-carried WAW
        ycbcr->Cb_b_tab[i] = (int)((D3 * x + ((int32)(1 << (16 - 1)))) >> 16);
        ycbcr->Cr_g_tab[i] = D2 * x;
        ycbcr->Cb_g_tab[i] = D4 * x + ((int32)(1 << (16 - 1)));
    }
}
