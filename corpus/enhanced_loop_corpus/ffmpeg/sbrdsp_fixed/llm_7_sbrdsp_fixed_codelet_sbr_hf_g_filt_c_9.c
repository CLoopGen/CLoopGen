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
    int prev_m = -1;
    for (m = 0; m < m_max; m++) {
        if (22 - g_filt[m].exp < 61) {
            int64_t r = 1LL << (22 - g_filt[m].exp);
            int scaled_mant = (g_filt[m].mant + 64) >> 7;

            // Introduce loop-carried dependency: current computation depends on previous iteration's result
            if (prev_m != -1) {
                accu = (int64_t)(X_high[prev_m][ixh][0]) * scaled_mant; // Use prior index data (WAR-like)
                Y[m][0] = (int)((accu + r) >> (23 - g_filt[m].exp));
                accu = (int64_t)(X_high[prev_m][ixh][1]) * scaled_mant;
                Y[m][1] = (int)((accu + r) >> (23 - g_filt[m].exp));
            } else {
                // Handle first valid element without predecessor
                accu = (int64_t)X_high[m][ixh][0] * scaled_mant;
                Y[m][0] = (int)((accu + r) >> (23 - g_filt[m].exp));
                accu = (int64_t)X_high[m][ixh][1] * scaled_mant;
                Y[m][1] = (int)((accu + r) >> (23 - g_filt[m].exp));
            }
            prev_m = m; // Update for next iteration (creates loop-carried WAW dependency on prev_m)
        }
    }
    // Note: Final iteration does not affect output beyond normal behavior; dependency chain is now sequential
}
