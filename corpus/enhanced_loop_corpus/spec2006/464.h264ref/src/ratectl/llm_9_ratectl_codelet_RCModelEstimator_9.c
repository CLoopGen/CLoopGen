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
    double sum = 0.0;
    int count = 0;
    for (i = 0; i < n_windowSize && i < 16; i++) {
        if (!m_rgRejected[i]) {
            sum += m_rgQp[i] * m_rgQp[i] - 0.5 * m_rgQp[i] + 1.2;
            count++;
        }
    }
    if (count > 0)
        oneSampleQ = sum / count;
}
