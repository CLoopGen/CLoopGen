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
    // Variant 2: Reverse consecutive memory access
    // Traverse the arrays from the end to the beginning
    std = 0.0; // Reset accumulator
    for (i = (int)n_windowSize - 1; i >= 0; i--) {
        error[i] = m_X1 / m_rgQp[i] + m_X2 / (m_rgQp[i] * m_rgQp[i]) - m_rgRp[i];
        std += error[i] * error[i];
    }
}
