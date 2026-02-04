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
    int shift_exp = 22 - g_filt[m].exp;
    int64_t r = (shift_exp < 61) ? (1LL << shift_exp) : 0;
    int valid = shift_exp < 61;
    int factor = valid ? ((g_filt[m].mant + 64) >> 7) : 0;
    accu = (int64_t)X_high[m][ixh][0] * factor;
    Y[m][0] = valid ? (int)((accu + r) >> (shift_exp + 1)) : 0;
    accu = (int64_t)X_high[m][ixh][1] * factor;
    Y[m][1] = valid ? (int)((accu + r) >> (shift_exp + 1)) : 0;
}
}
