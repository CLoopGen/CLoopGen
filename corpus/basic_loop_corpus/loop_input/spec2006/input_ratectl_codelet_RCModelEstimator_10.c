#include <stdio.h>
#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

Boolean m_rgRejected[21];
double m_rgQp[21];
double m_rgRp[21];
double m_X1;
int n_windowSize;
int n_realSize;
int i;
double oneSampleQ;
Boolean estimateX2;

void init_vars() {
    n_windowSize = 21;
    n_realSize = 21;
    oneSampleQ = 1.5;
    m_X1 = 0.0;
    estimateX2 = FALSE;

    for (int idx = 0; idx < 21; idx++) {
        m_rgRejected[idx] = (idx % 7 == 0) ? TRUE : FALSE;
        m_rgQp[idx] = 1.0 + idx * 0.5;
        m_rgRp[idx] = 2.0 + idx * 0.3;
    }
}