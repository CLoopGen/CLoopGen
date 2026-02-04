#include <stdio.h>
#include <inttypes.h>

double m_rgQp[21];
double m_rgRp[21];
double m_X1;
double m_X2;
int n_windowSize;
int i;
double error[20];
double std;

void init_vars() {
    n_windowSize = 20;  // Must be <= 20 to avoid buffer overflow in error[20] and within m_rgQp/m_rgRp bounds

    m_X1 = 1.5;
    m_X2 = 2.3;
    std = 0.0;

    for (int idx = 0; idx < 21; idx++) {
        m_rgQp[idx] = 1.0 + idx * 0.1;
        if (idx < 20) {
            m_rgRp[idx] = 0.5 + idx * 0.2;
        }
    }
}