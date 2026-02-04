#include <stdio.h>
#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

Boolean m_rgRejected[21];
double m_rgQp[21];
int n_windowSize;
int i;
double oneSampleQ;

void init_vars() {
    n_windowSize = 21;
    oneSampleQ = 0.0;

    for (int idx = 0; idx < 21; idx++) {
        m_rgRejected[idx] = (idx % 3 == 0) ? TRUE : FALSE;
        m_rgQp[idx] = 1.0 + idx * 0.5;
    }
}