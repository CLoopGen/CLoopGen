#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean m_rgRejected[21];
extern double m_rgQp[21];
extern double m_rgRp[21];
extern double m_X1;
extern int n_windowSize;
extern int n_realSize;
extern int i;
extern double oneSampleQ;
extern Boolean estimateX2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_accum = m_X1;
    for (i = 0; i < n_windowSize; i++) {
        double product = m_rgQp[i] * m_rgRp[i];
        if (!m_rgRejected[i]) {
            local_accum += product / n_realSize;
            if (m_rgQp[i] != oneSampleQ) {
                estimateX2 = TRUE;
            }
        }
    }
    m_X1 = local_accum;
}
