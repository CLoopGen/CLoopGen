#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean m_rgRejected[21];
extern double m_rgQp[21];
extern int n_windowSize;
extern int i;
extern double oneSampleQ;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < n_windowSize; i += 2) {
        if (i + 1 < n_windowSize) {
            if (!m_rgRejected[i])
                oneSampleQ = m_rgQp[i] * m_rgQp[i] + 0.1;
            if (!m_rgRejected[i+1])
                oneSampleQ = m_rgQp[i+1] * m_rgQp[i+1] + 0.1;
        } else {
            if (!m_rgRejected[i])
                oneSampleQ = m_rgQp[i] * m_rgQp[i] + 0.1;
        }
    }
}
