#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

TIFFYCbCrToRGB *ycbcr;
int i;
int32 D1 = 128;
int32 D2 = 64;
int32 D3 = 128;
int32 D4 = 64;
int32 D1_val = 128;
int32 D2_val = 64;
int32 D3_val = 128;
int32 D4_val = 64;
int x;

void init_vars() {
    ycbcr = (TIFFYCbCrToRGB*)malloc(sizeof(TIFFYCbCrToRGB));
    if (!ycbcr) return;

    size_t array_size = 256;

    ycbcr->clamptab = (TIFFRGBValue*)calloc(256 * 256, sizeof(TIFFRGBValue));
    ycbcr->Cr_r_tab = (int*)malloc(array_size * sizeof(int));
    ycbcr->Cb_b_tab = (int*)malloc(array_size * sizeof(int));
    ycbcr->Cr_g_tab = (int32*)malloc(array_size * sizeof(int32));
    ycbcr->Cb_g_tab = (int32*)malloc(array_size * sizeof(int32));

    for (int j = 0; j < 3; j++) {
        ycbcr->coeffs[j] = 1.0f;
    }

    D1 = D1_val;
    D2 = D2_val;
    D3 = D3_val;
    D4 = D4_val;

    if (!ycbcr->clamptab || !ycbcr->Cr_r_tab || !ycbcr->Cb_b_tab ||
        !ycbcr->Cr_g_tab || !ycbcr->Cb_g_tab) {
        return;
    }
}