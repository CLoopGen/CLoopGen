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
    // Variant 2: Reverse consecutive memory access
    // Traverse the arrays from the end to the beginning to modify access pattern
    int i;
    for (i = n_windowSize - 1; i >= 0; i--) {
        if ((m_rgQp[i] != oneSampleQ) && !m_rgRejected[i])
            estimateX2 = TRUE;
        if (!m_rgRejected[i])
            m_X1 += (m_rgQp[i] * m_rgRp[i]) / n_realSize;
    }
}
