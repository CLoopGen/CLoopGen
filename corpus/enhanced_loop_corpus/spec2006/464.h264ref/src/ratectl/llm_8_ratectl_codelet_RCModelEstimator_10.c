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
    int i = 0;
    double temp_sum = 0.0;
    Boolean localEstimateX2 = FALSE;
    const int step = 2;
    const int limit = (n_windowSize % 2 == 0) ? n_windowSize : n_windowSize - 1;

    for (i = 0; i < limit; i += step) {
        double qp_val1 = m_rgQp[i];
        double rp_val1 = m_rgRp[i];
        double qp_val2 = m_rgQp[i + 1];
        double rp_val2 = m_rgRp[i + 1];

        if ((qp_val1 != oneSampleQ) && !m_rgRejected[i])
            localEstimateX2 = TRUE;
        if ((qp_val2 != oneSampleQ) && !m_rgRejected[i + 1])
            localEstimateX2 = TRUE;

        if (!m_rgRejected[i])
            temp_sum += (qp_val1 * rp_val1);
        if (!m_rgRejected[i + 1])
            temp_sum += (qp_val2 * rp_val2);
    }

    if (limit < n_windowSize && !m_rgRejected[limit]) {
        double qp_val = m_rgQp[limit];
        double rp_val = m_rgRp[limit];
        temp_sum += (qp_val * rp_val);
        if (qp_val != oneSampleQ)
            localEstimateX2 = TRUE;
    }

    m_X1 += temp_sum / n_realSize;
    if (localEstimateX2)
        estimateX2 = TRUE;
}
