#include <stdio.h>

#include <inttypes.h>

extern double m_rgQp[21];
extern double m_rgRp[21];
extern double m_X1;
extern double m_X2;
extern int n_windowSize;
extern int i;
extern double error[20];
extern double std;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Arrays are accessed in a non-consecutive manner: i += 2
    std = 0.0; // Reset accumulator as per expected use
    for (i = 0; i < (int)n_windowSize; i += 2) {
        error[i] = m_X1 / m_rgQp[i] + m_X2 / (m_rgQp[i] * m_rgQp[i]) - m_rgRp[i];
        std += error[i] * error[i];
        // Handle boundary: ensure no out-of-bounds access for odd-sized windows
        if (i + 1 < (int)n_windowSize) {
            error[i+1] = m_X1 / m_rgQp[i+1] + m_X2 / (m_rgQp[i+1] * m_rgQp[i+1]) - m_rgRp[i+1];
            std += error[i+1] * error[i+1];
        }
    }
}
