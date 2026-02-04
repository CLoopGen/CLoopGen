#include <stdio.h>
#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

Boolean m_rgRejected[21];
double m_rgQp[21];
double m_rgRp[21];
int n_windowSize;
int i;
double a00;
double a01;
double a10;
double a11;
double b0;
double b1;

void init_vars() {
    n_windowSize = 21;
    for (i = 0; i < n_windowSize; i++) {
        m_rgRejected[i] = FALSE;
        m_rgQp[i] = 1.0 + (i * 0.1);
        m_rgRp[i] = 2.0 - (i * 0.05);
    }
    a00 = 0.0;
    a01 = 0.0;
    a10 = 0.0;
    a11 = 0.0;
    b0 = 0.0;
    b1 = 0.0;
}