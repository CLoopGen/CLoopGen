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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < n_windowSize; i += 2) {
        if (!m_rgRejected[i]) {
            a00 = a00 + 1.;
            a01 += 1. / m_rgQp[i];
            a10 = a01;
            a11 += 1. / (m_rgQp[i] * m_rgQp[i]);
            b0 += m_rgQp[i] * m_rgRp[i];
            b1 += m_rgRp[i];
        }
        // Process next element in the pair if within bounds
        int next_idx = i + 1;
        if (next_idx < n_windowSize && !m_rgRejected[next_idx]) {
            a00 = a00 + 1.;
            a01 += 1. / m_rgQp[next_idx];
            a10 = a01;
            a11 += 1. / (m_rgQp[next_idx] * m_rgQp[next_idx]);
            b0 += m_rgQp[next_idx] * m_rgRp[next_idx];
            b1 += m_rgRp[next_idx];
        }
    }
}
