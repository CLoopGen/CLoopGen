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
    for (i = 0; i < (int)n_windowSize; i++) {
        double inv_qp = 1.0 / m_rgQp[i];
        double term1 = m_X1 * inv_qp;
        double term2 = m_X2 * inv_qp * inv_qp;
        error[i] = term1 + term2 - m_rgRp[i];
        if (error[i] >= 0) {
            std += error[i] * error[i];
        }
    }
}
