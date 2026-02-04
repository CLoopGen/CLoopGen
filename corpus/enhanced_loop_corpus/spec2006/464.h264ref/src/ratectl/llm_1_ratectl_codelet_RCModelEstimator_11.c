#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean m_rgRejected[21];
extern double m_rgQp[21];
extern double m_rgRp[21];
extern int n_windowSize;
extern int i;
extern double a00;
extern double a01;
extern double a10;
extern double a11;
extern double b0;
extern double b1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_windowSize; i += 2) {
        for (int k = 0; k < 2 && (i + k) < n_windowSize; k++) {
            int idx = i + k;
            if (!m_rgRejected[idx]) {
                a00 = a00 + 1.;
                a01 += 1. / m_rgQp[idx];
                a10 = a01;
                a11 += 1. / (m_rgQp[idx] * m_rgQp[idx]);
                b0 += m_rgQp[idx] * m_rgRp[idx];
                b1 += m_rgRp[idx];
            }
        }
    }
}
