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
for (ib = 0; ib < nb; ++ib) {
    for (i = 0; i < n - 1; ++i) {
        for (ia = 0; ia < na; ++ia) {
            b[(ib * n + i) * na + ia] = a[(ib * n + i + 1) * na + ia];
        }
    }
    switch (k) {
      case R2R_DHT:
      case R2R_R2HC:
        for (ia = 0; ia < na; ++ia) {
            int idx_n_minus_1 = (ib * n + n - 1) * na + ia;
            int idx_0 = (ib * n + 0) * na + ia;
            b[idx_n_minus_1] = a[idx_0];
            b[idx_0] += a[idx_n_minus_1];
        }
        break;
      case R2R_HC2R:
        if (n > 2) {
            if (n % 2 == 0) {
                for (ia = 0; ia < na; ++ia) {
                    int base = ib * n * na + ia;
                    b[base + (n - 1)*na] = 0.;
                    b[base] += a[base + 1*na];
                    b[base + (n/2)*na] += +a[base + (n/2 - 1)*na] - a[base + (n/2 + 1)*na];
                    b[base + (n/2 + 1)*na] += -a[base + (n/2)*na];
                }
            } else {
                for (ia = 0; ia < na; ++ia) {
                    int base = ib * n * na + ia;
                    b[base + (n - 1)*na] = 0.;
                    b[base] += a[base + 1*na];
                    b[base + (n/2)*na] += +a[base + (n/2)*na] - a[base + (n/2 + 1)*na];
                    b[base + (n/2 + 1)*na] += -a[base + (n/2 + 1)*na] - a[base + (n/2)*na];
                }
            }
        } else {
            for (ia = 0; ia < na; ++ia) {
                int idx_n_minus_1 = (ib * n + n - 1) * na + ia;
                int idx_0 = (ib * n + 0) * na + ia;
                b[idx_n_minus_1] = a[idx_0];
                b[idx_0] += a[idx_n_minus_1];
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
        for (ia = 0; ia < na; ++ia) {
            int idx_n_minus_1 = (ib * n + n - 1) * na + ia;
            int idx_n_minus_2 = (ib * n + n - 2) * na + ia;
            int idx_0 = (ib * n) * na + ia;
            int idx_1 = (ib * n + 1) * na + ia;
            b[idx_n_minus_1] = isR0 * a[idx_n_minus_1] + (n > 1 ? isR1 * a[idx_n_minus_2] : 0);
            b[idx_0] += isL0 * a[idx_0] + (n > 1 ? isL1 * a[idx_1] : 0);
        }
    }
    for (i = 1; i < n; ++i) {
        for (ia = 0; ia < na; ++ia) {
            b[(ib * n + i) * na + ia] += a[(ib * n + i - 1) * na + ia];
        }
    }
}
}
