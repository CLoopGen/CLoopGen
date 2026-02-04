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
    double local_std = 0.0;
    for (i = 0; i < (int)n_windowSize; i++) {
        double qpi = m_rgQp[i];
        double inv_qpi = 1.0 / qpi;
        double term1 = m_X1 * inv_qpi;
        double term2 = m_X2 * (inv_qpi * inv_qpi);
        error[i] = term1 + term2 - m_rgRp[i];
        local_std += error[i] * error[i];
    }
    std += local_std;
}
