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
    int32 temp_Cr_g, temp_Cb_g;
    for (i = 0, x = -128; i < 256; i++, x++) {
        int cr_r_val = (int)((D1 * x + ((int32)(1 << (15)))) >> 16);
        int cb_b_val = (int)((D3 * x + ((int32)(1 << (15)))) >> 16);
        temp_Cr_g = D2 * x;
        temp_Cb_g = D4 * x + ((int32)(1 << 15));
        
        ycbcr->Cr_r_tab[i] = cr_r_val;
        ycbcr->Cb_b_tab[i] = cb_b_val;
        ycbcr->Cr_g_tab[i] = temp_Cr_g;
        ycbcr->Cb_g_tab[i] = temp_Cb_g;
    }
}
