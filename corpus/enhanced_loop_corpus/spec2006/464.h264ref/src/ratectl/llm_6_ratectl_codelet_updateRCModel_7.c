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
    double temp_error;
    for (i = 0; i < (int)n_windowSize; i++) {
        temp_error = m_X1 / m_rgQp[i] + m_X2 / (m_rgQp[i] * m_rgQp[i]) - m_rgRp[i];
        error[i] = temp_error;
        std += temp_error * temp_error;
    }
}
