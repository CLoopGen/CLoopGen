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
    // Unroll the innermost loop by a factor of 2 to increase computational intensity
    for (i = 0; i < n - 1; ++i) {
        int idx_base = (ib * n + i) * na;
        int idx_src = (ib * n + i + 1) * na;
        ia = 0;
        // Loop unrolling with stride 2
        for (; ia + 1 < na; ia += 2) {
            b[idx_base + ia] = a[idx_src + ia];
            b[idx_base + ia + 1] = a[idx_src + ia + 1];
        }
        // Handle remaining element if na is odd
        if (ia < na) {
            b[idx_base + ia] = a[idx_src + ia];
        }
    }
    switch (k) {
      case R2R_DHT:
      case R2R_R2HC:
        for (ia = 0; ia < na; ++ia) {
            int idx_last = (ib * n + n - 1) * na + ia;
            int idx_first = (ib * n) * na + ia;
            b[idx_last] = a[idx_first];
            b[idx_first] += a[idx_last];
        }
        break;
      case R2R_HC2R:
        if (n > 2) {
            int n2 = n / 2;
            if (n % 2 == 0) {
                for (ia = 0; ia < na; ++ia) {
                    int idx_n1 = (ib * n + n - 1) * na + ia;
                    int idx_0 = (ib * n) * na + ia;
                    int idx_n2 = (ib * n + n2) * na + ia;
                    int idx_n2p1 = (ib * n + n2 + 1) * na + ia;
                    int idx_n2m1 = (ib * n + n2 - 1) * na + ia;
                    b[idx_n1] = 0.;
                    b[idx_0] += a[(ib * n + 1) * na + ia];
                    b[idx_n2] += a[idx_n2m1] - a[idx_n2p1];
                    b[idx_n2p1] += -a[idx_n2];
                }
            } else {
                for (ia = 0; ia < na; ++ia) {
                    int idx_n1 = (ib * n + n - 1) * na + ia;
                    int idx_0 = (ib * n) * na + ia;
                    int idx_n2 = (ib * n + n2) * na + ia;
                    int idx_n2p1 = (ib * n + n2 + 1) * na + ia;
                    b[idx_n1] = 0.;
                    b[idx_0] += a[(ib * n + 1) * na + ia];
                    b[idx_n2] += a[idx_n2] - a[idx_n2p1];
                    b[idx_n2p1] += -a[idx_n2p1] - a[idx_n2];
                }
            }
        } else {
            for (ia = 0; ia < na; ++ia) {
                int idx_last = (ib * n + n - 1) * na + ia;
                int idx_first = (ib * n) * na + ia;
                b[idx_last] = a[idx_first];
                b[idx_first] += a[idx_last];
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
            int idx_last = (ib * n + n - 1) * na + ia;
            int idx_second_last = (ib * n + n - 2) * na + ia;
            b[idx_last] = isR0 * a[idx_last] + (n > 1 ? isR1 * a[idx_second_last] : 0);
        }
        for (ia = 0; ia < na; ++ia) {
            int idx_0 = (ib * n) * na + ia;
            int idx_1 = (ib * n + 1) * na + ia;
            b[idx_0] += isL0 * a[idx_0] + (n > 1 ? isL1 * a[idx_1] : 0);
        }
    }
    // Increase arithmetic operations per iteration: add two previous elements
    for (i = 1; i < n; ++i) {
        int idx_dst = (ib * n + i) * na;
        int idx_prev1 = (ib * n + i - 1) * na;
        int idx_prev2 = (ib * n + (i - 2 >= 0 ? i - 2 : 0)) * na;
        for (ia = 0; ia < na; ++ia) {
            b[idx_dst + ia] += a[idx_prev1 + ia] + a[idx_prev2 + ia];
        }
    }
}
}
