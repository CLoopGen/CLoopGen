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
    // Variant 2: Use indirect (gather-scatter) access via index arrays to simulate irregular memory patterns
    // Although the access is regular in logic, we simulate indirect indexing for flexibility and cache behavior change

    // Precompute linear indices for all positions used frequently
    int *idx_a = (int*)alloca(n * sizeof(int));
    int *idx_b = (int*)alloca(n * sizeof(int));
    int *idx_na = (int*)alloca(na * sizeof(int));

    // Cache na offsets
    for (int ia = 0; ia < na; ++ia)
        idx_na[ia] = ia;

    for (int ib = 0; ib < nb; ++ib) {
        // Precompute base offsets for current ib block
        int base_offset = ib * n * na;
        for (int i = 0; i < n; ++i) {
            idx_a[i] = base_offset + i * na;
            idx_b[i] = base_offset + i * na;
        }

        // First loop: shift forward using indirect addressing
        for (int i = 0; i < n - 1; ++i) {
            int src_idx = idx_a[i + 1];
            int dst_idx = idx_b[i];
            for (int j = 0; j < na; ++j) {
                int ia = idx_na[j];
                b[dst_idx + ia] = a[src_idx + ia];
            }
        }

        switch (k) {
          case R2R_DHT:
          case R2R_R2HC: {
            int last_dst = idx_b[n - 1];
            int first_dst = idx_b[0];
            int first_src = idx_a[0];
            int last_src = idx_a[n - 1];
            for (int j = 0; j < na; ++j) {
                int ia = idx_na[j];
                b[last_dst + ia] = a[first_src + ia];
                b[first_dst + ia] += a[last_src + ia];
            }
            break;
          }
          case R2R_HC2R:
            if (n > 2) {
                if (n % 2 == 0) {
                    for (int j = 0; j < na; ++j) {
                        int ia = idx_na[j];
                        b[idx_b[n - 1] + ia] = 0.;
                        b[idx_b[0] + ia] += a[idx_a[1] + ia];
                        b[idx_b[n/2] + ia] += a[idx_a[n/2 - 1] + ia] - a[idx_a[n/2 + 1] + ia];
                        b[idx_b[n/2 + 1] + ia] += -a[idx_a[n/2] + ia];
                    }
                } else {
                    for (int j = 0; j < na; ++j) {
                        int ia = idx_na[j];
                        b[idx_b[n - 1] + ia] = 0.;
                        b[idx_b[0] + ia] += a[idx_a[1] + ia];
                        b[idx_b[n/2] + ia] += a[idx_a[n/2] + ia] - a[idx_a[n/2 + 1] + ia];
                        b[idx_b[n/2 + 1] + ia] += -a[idx_a[n/2 + 1] + ia] - a[idx_a[n/2] + ia];
                    }
                }
            } else {
                for (int j = 0; j < na; ++j) {
                    int ia = idx_na[j];
                    b[idx_b[n - 1] + ia] = a[idx_a[0] + ia];
                    b[idx_b[0] + ia] += a[idx_a[n - 1] + ia];
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
            for (int j = 0; j < na; ++j) {
                int ia = idx_na[j];
                b[idx_b[n - 1] + ia] = isR0 * a[idx_a[n - 1] + ia] + 
                                       (n > 1 ? isR1 * a[idx_a[n - 2] + ia] : 0);
            }
            for (int j = 0; j < na; ++j) {
                int ia = idx_na[j];
                b[idx_b[0] + ia] += isL0 * a[idx_a[0] + ia] + (n > 1 ? isL1 * a[idx_a[1] + ia] : 0);
            }
        }

        // Final accumulation loop using indirect access
        for (int i = 1; i < n; ++i) {
            int src_idx = idx_a[i - 1];
            int dst_idx = idx_b[i];
            for (int j = 0; j < na; ++j) {
                int ia = idx_na[j];
                b[dst_idx + ia] += a[src_idx + ia];
            }
        }
    }
}
