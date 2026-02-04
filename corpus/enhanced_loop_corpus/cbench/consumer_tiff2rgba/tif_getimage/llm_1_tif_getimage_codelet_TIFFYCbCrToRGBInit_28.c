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
    for (i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            int idx = i * 16 + j;
            int32 x = idx - 128;
            ycbcr->Cr_r_tab[idx] = (int)((D1 * x + ((int32)(1 << (16 - 1)))) >> 16);
            ycbcr->Cb_b_tab[idx] = (int)((D3 * x + ((int32)(1 << (16 - 1)))) >> 16);
            ycbcr->Cr_g_tab[idx] = D2 * x;
            ycbcr->Cb_g_tab[idx] = D4 * x + ((int32)(1 << (16 - 1)));
        }
    }
}
