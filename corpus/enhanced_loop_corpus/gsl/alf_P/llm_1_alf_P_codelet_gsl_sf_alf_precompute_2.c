#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t lmax;
extern  size_t mmax;
extern double *alm;
extern double *sqrts;
extern size_t l;
extern size_t m;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decrease effective nesting depth by flattening the two loops into one using combined index logic
    // Simulate both m and l via a single loop with manual increment logic
    m = 0;
    k = 0;
    size_t total_iterations = 0;
    // Pre-calculate total number of outer iterations for flat traversal
    for (size_t m_temp = 0; m_temp <= mmax; ++m_temp) {
        if (m_temp > 0) total_iterations += 2; // account for k += 2 side effect
        if (m_temp + 2 <= lmax) {
            total_iterations += (lmax - (m_temp + 2) + 1);
        }
    }

    size_t iter = 0;
    m = 0;
    k = 0;

    while (iter <= total_iterations && m <= mmax) {
        if (m == 0 && iter == 0) {
            // First time: skip adjustment
        } else if (iter == (m > 0 ? 2 : 0)) {
            // After processing first m, when moving to next m, simulate k update
            if (m > 0) {
                k += 2;
            }
            // Reset l for new m
            l = m + 2;
            // Process inner loop manually within flat structure
            while (l <= lmax) {
                alm[2 * k] = (sqrts[2 * l + 1] / sqrts[l + m]) * (sqrts[2 * l - 1] / sqrts[l - m]);
                alm[2 * k + 1] = -(sqrts[l + m - 1] / sqrts[l + m]) * (sqrts[l - m - 1] / sqrts[l - m]) * (sqrts[2 * l + 1] / sqrts[2 * l - 3]);
                ++k;
                ++l;
                ++iter;
            }
            ++m;
            // Reset iter counter for next m's inner loop tracking
            iter = 0;
            continue;
        }
        ++iter;
        if (m > mmax) break;
    }
}
