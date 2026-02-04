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
    double temp_X1 = 0.0;
    Boolean temp_estimateX2 = FALSE;
    for (i = 0; i < n_windowSize; i++) {
        if ((m_rgQp[i] != oneSampleQ) && !m_rgRejected[i])
            temp_estimateX2 = TRUE;
        if (!m_rgRejected[i])
            temp_X1 += (m_rgQp[i] * m_rgRp[i]) / n_realSize;
    }
    m_X1 = temp_X1;
    estimateX2 = temp_estimateX2;
}
