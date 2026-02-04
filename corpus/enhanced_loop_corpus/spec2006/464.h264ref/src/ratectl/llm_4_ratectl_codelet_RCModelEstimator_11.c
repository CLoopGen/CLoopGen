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
    for (i = 0; i < n_windowSize; i++) {
        if (m_rgRejected[i]) {
            continue;
        }
        a00 = a00 + 1.;
        a01 += 1. / m_rgQp[i];
        a10 = a01;
        a11 += 1. / (m_rgQp[i] * m_rgQp[i]);
        b0 += m_rgQp[i] * m_rgRp[i];
        b1 += m_rgRp[i];
    }
}
