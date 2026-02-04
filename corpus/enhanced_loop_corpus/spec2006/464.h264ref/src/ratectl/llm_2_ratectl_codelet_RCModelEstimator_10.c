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
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // This variant accesses elements in a strided pattern to change spatial locality
    int i;
    for (i = 0; i < n_windowSize; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;

        if (idx1 < n_windowSize) {
            if ((m_rgQp[idx1] != oneSampleQ) && !m_rgRejected[idx1])
                estimateX2 = TRUE;
            if (!m_rgRejected[idx1])
                m_X1 += (m_rgQp[idx1] * m_rgRp[idx1]) / n_realSize;
        }

        if (idx2 < n_windowSize) {
            if ((m_rgQp[idx2] != oneSampleQ) && !m_rgRejected[idx2])
                estimateX2 = TRUE;
            if (!m_rgRejected[idx2])
                m_X1 += (m_rgQp[idx2] * m_rgRp[idx2]) / n_realSize;
        }
    }
}
