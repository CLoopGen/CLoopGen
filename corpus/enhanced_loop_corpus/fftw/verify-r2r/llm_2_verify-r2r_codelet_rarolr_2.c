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



void loop() {
    // Variant 1: Modify memory access pattern to use strided access with precomputed base pointers
    // Instead of recalculating (ib * n + i) * na + ia each time, we precompute row and column strides
    for (int ib = 0; ib < nb; ++ib) {
        R *base_b = b + ib * n * na;
        R *base_a = a + ib * n * na;

        // First inner loop: shift elements forward with stride-na access
        for (int i = 0; i < n - 1; ++i) {
            R *src_row = base_a + (i + 1) * na;
            R *dst_row = base_b + i * na;
            for (int ia = 0; ia < na; ++ia) {
                dst_row[ia] = src_row[ia];
            }
        }

        switch (k) {
          case R2R_DHT:
          case R2R_R2HC: {
            R *dst_last = base_b + (n - 1) * na;
            R *dst_first = base_b;
            R *src_first = base_a;
            R *src_last = base_a + (n - 1) * na;
            for (int ia = 0; ia < na; ++ia) {
                dst_last[ia] = src_first[ia];
                dst_first[ia] += src_last[ia];
            }
            break;
          }
          case R2R_HC2R:
            if (n > 2) {
                if (n % 2 == 0) {
                    for (int ia = 0; ia < na; ++ia) {
                        base_b[(n - 1) * na + ia] = 0.;
                        base_b[ia] += base_a[na + ia];
                        base_b[(n / 2) * na + ia] += base_a[(n / 2 - 1) * na + ia] - base_a[(n / 2 + 1) * na + ia];
                        base_b[(n / 2 + 1) * na + ia] += -base_a[(n / 2) * na + ia];
                    }
                } else {
                    for (int ia = 0; ia < na; ++ia) {
                        base_b[(n - 1) * na + ia] = 0.;
                        base_b[ia] += base_a[na + ia];
                        base_b[(n / 2) * na + ia] += base_a[(n / 2) * na + ia] - base_a[(n / 2 + 1) * na + ia];
                        base_b[(n / 2 + 1) * na + ia] += -base_a[(n / 2 + 1) * na + ia] - base_a[(n / 2) * na + ia];
                    }
                }
            } else {
                for (int ia = 0; ia < na; ++ia) {
                    base_b[(n - 1) * na + ia] = base_a[ia];
                    base_b[ia] += base_a[(n - 1) * na + ia];
                }
            }
            break;
          case R2R_REDFT00:
            isL1 = isR1 = 1;
            goto mirrors;
          case R2R_REDFT01:
            isL1 = 1;
            goto mirrors;
          case R2R_REDFT10:
            isL0 = isR0 = 1;
            goto mirrors;
          case R2R_REDFT11:
            isL0 = 1;
            isR0 = -1;
            goto mirrors;
          case R2R_RODFT00:
            goto mirrors;
          case R2R_RODFT01:
            isR1 = 1;
            goto mirrors;
          case R2R_RODFT10:
            isL0 = isR0 = -1;
            goto mirrors;
          case R2R_RODFT11:
            isL0 = -1;
            isR0 = 1;
            goto mirrors;
          mirrors:
            for (int ia = 0; ia < na; ++ia) {
                base_b[(n - 1) * na + ia] = isR0 * base_a[(n - 1) * na + ia] + 
                                           (n > 1 ? isR1 * base_a[(n - 2) * na + ia] : 0);
            }
            for (int ia = 0; ia < na; ++ia) {
                base_b[ia] += isL0 * base_a[ia] + (n > 1 ? isL1 * base_a[na + ia] : 0);
            }
        }

        // Final loop: backward accumulation with strided access
        for (int i = 1; i < n; ++i) {
            R *src_prev = base_a + (i - 1) * na;
            R *dst_curr = base_b + i * na;
            for (int ia = 0; ia < na; ++ia) {
                dst_curr[ia] += src_prev[ia];
            }
        }
    }
}
