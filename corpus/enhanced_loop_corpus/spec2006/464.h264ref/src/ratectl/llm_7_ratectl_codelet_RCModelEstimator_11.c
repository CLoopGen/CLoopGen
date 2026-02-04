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
    double local_a00 = a00;
    double local_a11 = a11;
    double local_b0 = b0;
    double sum_reciprocal_qp = 0.0;
    double sum_reciprocal_qp_sq = 0.0;
    double sum_rp = 0.0;

    // Introduce loop-carried WAW and WAR dependencies via staged accumulation
    for (i = 0; i < n_windowSize; i++) {
        if (!m_rgRejected[i]) {
            local_a00 += 1.0;

            double inv_qp = 1.0 / m_rgQp[i];
            sum_reciprocal_qp += inv_qp; // WAR: sum updated after use in prior iterations
            sum_reciprocal_qp_sq += inv_qp * inv_qp;

            double qp_times_rp = m_rgQp[i] * m_rgRp[i];
            local_b0 += qp_times_rp; // WAW: local_b0 written each iteration

            sum_rp += m_rgRp[i];
        }
    }

    // Final assignments to break loop-carried output dependence
    a00 = local_a00;
    a01 += sum_reciprocal_qp;       // Accumulate all reciprocal Qp values
    a10 = a01;                      // RAW: a10 depends on updated a01
    a11 += sum_reciprocal_qp_sq;
    b0 = local_b0;
    b1 += sum_rp;
}
