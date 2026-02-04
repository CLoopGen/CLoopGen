#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean m_rgRejected[21];
extern double m_rgQp[21];
extern double m_rgRp[21];
extern int n_windowSize;
extern int i;
extern double a00;
extern double a01;
extern double a10;
extern double a11;
extern double b0;
extern double b1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_a00 = a00;
    double temp_a01 = a01;
    double temp_a10 = 0.0;
    double temp_a11 = a11;
    double temp_b0 = b0;
    double temp_b1 = b1;

    for (i = 0; i < n_windowSize; i++) {
        if (!m_rgRejected[i]) {
            temp_a00 += 1.0;
            temp_a01 += 1.0 / m_rgQp[i];
            temp_a10 = temp_a01; // RAW dependency: temp_a10 depends on updated temp_a01
            temp_a11 += 1.0 / (m_rgQp[i] * m_rgQp[i]);
            temp_b0 += m_rgQp[i] * m_rgRp[i];
            temp_b1 += m_rgRp[i];
        }
    }

    // Eliminate loop-carried dependencies by updating global variables only after loop
    a00 = temp_a00;
    a01 = temp_a01;
    a10 = temp_a10;
    a11 = temp_a11;
    b0 = temp_b0;
    b1 = temp_b1;
}
