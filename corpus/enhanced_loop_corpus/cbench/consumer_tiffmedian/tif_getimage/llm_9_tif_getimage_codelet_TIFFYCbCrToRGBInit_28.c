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
    for (i = 0; i < 256; i += 4) {
        int offsets[4];
        for (int j = 0; j < 4; j++) {
            offsets[j] = i + j - 128;
        }
        ycbcr->Cr_r_tab[i]     = (int)((D1 * offsets[0] + (1 << 15)) >> 16);
        ycbcr->Cb_b_tab[i]     = (int)((D3 * offsets[0] + (1 << 15)) >> 16);
        ycbcr->Cr_g_tab[i]     = D2 * offsets[0];
        ycbcr->Cb_g_tab[i]     = D4 * offsets[0] + (1 << 15);

        if (i+1 < 256) {
            ycbcr->Cr_r_tab[i+1] = (int)((D1 * offsets[1] + (1 << 15)) >> 16);
            ycbcr->Cb_b_tab[i+1] = (int)((D3 * offsets[1] + (1 << 15)) >> 16);
            ycbcr->Cr_g_tab[i+1] = D2 * offsets[1];
            ycbcr->Cb_g_tab[i+1] = D4 * offsets[1] + (1 << 15);
        }
        if (i+2 < 256) {
            ycbcr->Cr_r_tab[i+2] = (int)((D1 * offsets[2] + (1 << 15)) >> 16);
            ycbcr->Cb_b_tab[i+2] = (int)((D3 * offsets[2] + (1 << 15)) >> 16);
            ycbcr->Cr_g_tab[i+2] = D2 * offsets[2];
            ycbcr->Cb_g_tab[i+2] = D4 * offsets[2] + (1 << 15);
        }
        if (i+3 < 256) {
            ycbcr->Cr_r_tab[i+3] = (int)((D1 * offsets[3] + (1 << 15)) >> 16);
            ycbcr->Cb_b_tab[i+3] = (int)((D3 * offsets[3] + (1 << 15)) >> 16);
            ycbcr->Cr_g_tab[i+3] = D2 * offsets[3];
            ycbcr->Cb_g_tab[i+3] = D4 * offsets[3] + (1 << 15);
        }
    }
}
