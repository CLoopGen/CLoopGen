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
    int offset;
    for (i = 0; i < 256; i++) {
        offset = i - 128;
        ycbcr->Cr_r_tab[i] = (int)(((int32)D1 * offset + (1 << 15)) >> 16);
        ycbcr->Cr_g_tab[i] = (int32)D2 * offset;
        if (i > 0) {
            ycbcr->Cb_b_tab[i-1] = (int)(((int32)D3 * (offset - 1) + (1 << 15)) >> 16);
            ycbcr->Cb_g_tab[i-1] = (int32)D4 * (offset - 1) + (1 << 15);
        }
    }
    ycbcr->Cb_b_tab[255] = (int)(((int32)D3 * 127 + (1 << 15)) >> 16);
    ycbcr->Cb_g_tab[255] = (int32)D4 * 127 + (1 << 15);
}
