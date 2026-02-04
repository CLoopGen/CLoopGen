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
    int i;
    double sum = m_X1;
    Boolean flag = estimateX2;

    for (i = 0; i < n_windowSize && i < 16; i++) {
        double q = m_rgQp[i];
        double r = m_rgRp[i];
        Boolean rejected = m_rgRejected[i];

        if (!rejected) {
            sum += (q * r) / n_realSize;
            if (q != oneSampleQ) {
                flag = TRUE;
            }
        }
    }

    m_X1 = sum;
    estimateX2 = flag;
}
