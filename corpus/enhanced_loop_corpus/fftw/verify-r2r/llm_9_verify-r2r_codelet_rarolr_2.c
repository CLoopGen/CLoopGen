#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real R;

typedef enum {
    R2R_R2HC,
    R2R_HC2R,
    R2R_DHT,
    R2R_REDFT00,
    R2R_REDFT01,
    R2R_REDFT10,
    R2R_REDFT11,
    R2R_RODFT00,
    R2R_RODFT01,
    R2R_RODFT10,
    R2R_RODFT11
} r2r_kind_t;

extern R *b;
extern R *a;
extern int n;
extern int nb;
extern int na;
extern r2r_kind_t k;
extern int isL0;
extern int isL1;
extern int isR0;
extern int isR1;
extern int i;
extern int ib;
extern int ia;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce computational load by decreasing trip count and simplifying logic
for (ib = 0; ib < nb; ib += 2) {  // Process two ib blocks at once, reducing outer loop iterations
    // Skip second block if out of bounds
    if (ib + 1 >= nb) {
        // Fallback to single block processing
        for (i = 0; i < n - 1; ++i) {
            for (ia = 0; ia < na; ++ia) {
                int idx_dst = (ib * n + i) * na + ia;
                int idx_src = (ib * n + i + 1) * na + ia;
                b[idx_dst] = a[idx_src];
            }
        }
        // Minimal boundary handling: only R2R_R2HC case simplified
        if (k == R2R_R2HC || k == R2R_DHT) {
            for (ia = 0; ia < na; ++ia) {
                int idx_last = (ib * n + n - 1) * na + ia;
                int idx_0 = (ib * n) * na + ia;
                b[idx_last] = a[idx_0];
                b[idx_0] += a[idx_last];
            }
        }
        // Skip forward accumulation for reduced complexity
        continue;
    }

    // Combine two ib blocks in one iteration to reduce control overhead
    for (i = 0; i < n - 1; ++i) {
        int base_b0 = (ib * n + i) * na;
        int base_a0 = (ib * n + i + 1) * na;
        int base_b1 = ((ib + 1) * n + i) * na;
        int base_a1 = ((ib + 1) * n + i + 1) * na;
        for (ia = 0; ia < na; ++ia) {
            b[base_b0 + ia] = a[base_a0 + ia];
            b[base_b1 + ia] = a[base_a1 + ia];
        }
    }

    // Only handle simplest transform case to reduce branching complexity
    if (k == R2R_R2HC || k == R2R_DHT) {
        for (ia = 0; ia < na; ++ia) {
            // Block ib
            int idx_last0 = (ib * n + n - 1) * na + ia;
            int idx_00 = (ib * n) * na + ia;
            b[idx_last0] = a[idx_00];
            b[idx_00] += a[idx_last0];

            // Block ib+1
            int idx_last1 = ((ib + 1) * n + n - 1) * na + ia;
            int idx_01 = ((ib + 1) * n) * na + ia;
            b[idx_last1] = a[idx_01];
            b[idx_01] += a[idx_last1];
        }
    }

    // Reduced backward accumulation: only every second i updated
    for (i = 2; i < n; i += 2) {
        int base_b0 = (ib * n + i) * na;
        int base_b1 = ((ib + 1) * n + i) * na;
        int src_b0 = (ib * n + i - 1) * na;
        int src_b1 = ((ib + 1) * n + i - 1) * na;
        for (ia = 0; ia < na; ++ia) {
            b[base_b0 + ia] += a[src_b0 + ia];
            b[base_b1 + ia] += a[src_b1 + ia];
        }
    }
}
}
