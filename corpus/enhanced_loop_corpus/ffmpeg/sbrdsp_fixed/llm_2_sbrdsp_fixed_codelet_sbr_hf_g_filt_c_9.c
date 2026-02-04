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
for (m = 0; m < m_max; m++) {
    int idx = m;
    if (22 - g_filt[idx].exp < 61) {
        int64_t r = 1LL << (22 - g_filt[idx].exp);
        accu = (int64_t)X_high[idx][ixh][0] * ((g_filt[idx].mant + 64) >> 7);
        Y[idx][0] = (int)((accu + r) >> (23 - g_filt[idx].exp));
        accu = (int64_t)X_high[idx][ixh][1] * ((g_filt[idx].mant + 64) >> 7);
        Y[idx][1] = (int)((accu + r) >> (23 - g_filt[idx].exp));
    }
}
}
