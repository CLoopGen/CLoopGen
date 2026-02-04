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
    // Variant 2: Eliminate apparent dependencies by unrolling and reordering independent operations
    // Remove potential false dependencies by computing all values first, then storing
    // Also split into two phases to remove any intra-loop data dependencies (RAW/WAR)
    for (i = 0, x = -128; i < 256; i += 2, x += 2) {
        // Compute current and next iteration values in advance to break ordering assumptions
        int cr_r_val1 = (int)(((int32)D1 * x + ((int32)(1 << (15)))) >> 16);
        int cb_b_val1 = (int)(((int32)D3 * x + ((int32)(1 << (15)))) >> 16);
        int32 cr_g_val1 = D2 * x;
        int32 cb_g_val1 = D4 * x + ((int32)(1 << (15)));

        int cr_r_val2 = (int)(((int32)D1 * (x+1) + ((int32)(1 << (15)))) >> 16);
        int cb_b_val2 = (int)(((int32)D3 * (x+1) + ((int32)(1 << (15)))) >> 16);
        int32 cr_g_val2 = D2 * (x+1);
        int32 cb_g_val2 = D4 * (x+1) + ((int32)(1 << (15)));

        // Store in non-sequential order to break predictable access patterns (no actual dependency)
        ycbcr->Cr_r_tab[i]   = cr_r_val1;
        ycbcr->Cr_r_tab[i+1] = cr_r_val2;
        ycbcr->Cb_b_tab[i]   = cb_b_val1;
        ycbcr->Cb_b_tab[i+1] = cb_b_val2;
        ycbcr->Cr_g_tab[i]   = cr_g_val1;
        ycbcr->Cr_g_tab[i+1] = cr_g_val2;
        ycbcr->Cb_g_tab[i]   = cb_g_val1;
        ycbcr->Cb_g_tab[i+1] = cb_g_val2;
    }
    // Handle odd-sized case if needed (though 256 is even, so safe)
}
