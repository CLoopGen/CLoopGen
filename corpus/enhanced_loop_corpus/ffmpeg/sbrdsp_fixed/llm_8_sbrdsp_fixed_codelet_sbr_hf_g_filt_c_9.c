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
    if (m + 1 >= m_max) break;
    if (22 - g_filt[m].exp < 61) {
        int64_t r = 1LL << (22 - g_filt[m].exp);
        accu = (int64_t)X_high[m][ixh][0] * ((g_filt[m].mant + 64) >> 7);
        Y[m][0] = (int)((accu + r) >> (23 - g_filt[m].exp));
        accu = (int64_t)X_high[m][ixh][1] * ((g_filt[m].mant + 64) >> 7);
        Y[m][1] = (int)((accu + r) >> (23 - g_filt[m].exp));
    }
    if (22 - g_filt[m+1].exp < 61) {
        int64_t r_next = 1LL << (22 - g_filt[m+1].exp);
        accu = (int64_t)X_high[m+1][ixh][0] * ((g_filt[m+1].mant + 64) >> 7);
        Y[m+1][0] = (int)((accu + r_next) >> (23 - g_filt[m+1].exp));
        accu = (int64_t)X_high[m+1][ixh][1] * ((g_filt[m+1].mant + 64) >> 7);
        Y[m+1][1] = (int)((accu + r_next) >> (23 - g_filt[m+1].exp));
    }
}
}
