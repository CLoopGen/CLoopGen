#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SoftFloat {
    int32_t mant;
    int32_t exp;
} SoftFloat;

extern int (*Y)[2];
extern  int (*X_high)[40][2];
extern  SoftFloat *g_filt;
extern int m_max;
extern intptr_t ixh;
extern int m;
extern int64_t accu;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = 0; m < m_max; m += 2) {
    int idx1 = m;
    int idx2 = m + 1;
    if (idx2 < m_max) {
        if (22 - g_filt[idx1].exp < 61) {
            int64_t r1 = 1LL << (22 - g_filt[idx1].exp);
            accu = (int64_t)X_high[idx1][ixh][0] * ((g_filt[idx1].mant + 64) >> 7);
            Y[idx1][0] = (int)((accu + r1) >> (23 - g_filt[idx1].exp));
            accu = (int64_t)X_high[idx1][ixh][1] * ((g_filt[idx1].mant + 64) >> 7);
            Y[idx1][1] = (int)((accu + r1) >> (23 - g_filt[idx1].exp));
        }
        if (22 - g_filt[idx2].exp < 61) {
            int64_t r2 = 1LL << (22 - g_filt[idx2].exp);
            accu = (int64_t)X_high[idx2][ixh][0] * ((g_filt[idx2].mant + 64) >> 7);
            Y[idx2][0] = (int)((accu + r2) >> (23 - g_filt[idx2].exp));
            accu = (int64_t)X_high[idx2][ixh][1] * ((g_filt[idx2].mant + 64) >> 7);
            Y[idx2][1] = (int)((accu + r2) >> (23 - g_filt[idx2].exp));
        }
    } else {
        if (22 - g_filt[idx1].exp < 61) {
            int64_t r1 = 1LL << (22 - g_filt[idx1].exp);
            accu = (int64_t)X_high[idx1][ixh][0] * ((g_filt[idx1].mant + 64) >> 7);
            Y[idx1][0] = (int)((accu + r1) >> (23 - g_filt[idx1].exp));
            accu = (int64_t)X_high[idx1][ixh][1] * ((g_filt[idx1].mant + 64) >> 7);
            Y[idx1][1] = (int)((accu + r1) >> (23 - g_filt[idx1].exp));
        }
    }
}
}
