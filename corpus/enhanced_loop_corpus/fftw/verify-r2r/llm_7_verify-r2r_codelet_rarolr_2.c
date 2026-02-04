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
    // Reverse loop order to change loop-carried dependency direction (from forward to backward)
    // This introduces anti-dependence (WAR) elimination by processing in reverse

    // Last element processed first to allow safe overwriting
    switch (k) {
      case R2R_DHT:
      case R2R_R2HC:
        for (ia = 0; ia < na; ++ia) {
            b[(ib * n + n - 1) * na + ia] = a[(ib * n + 0) * na + ia];
            b[(ib * n + 0) * na + ia] += a[(ib * n + n - 1) * na + ia];
        }
        break;
      case R2R_HC2R:
        if (n > 2) {
            if (n % 2 == 0)
                for (ia = 0; ia < na; ++ia) {
                    b[(ib * n + n - 1) * na + ia] = 0.;
                    b[(ib * n + 0) * na + ia] += a[(ib * n + 1) * na + ia];
                    b[(ib * n + n / 2) * na + ia] += +a[(ib * n + n / 2 - 1) * na + ia] - a[(ib * n + n / 2 + 1) * na + ia];
                    b[(ib * n + n / 2 + 1) * na + ia] += -a[(ib * n + n / 2) * na + ia];
                }
            else
                for (ia = 0; ia < na; ++ia) {
                    b[(ib * n + n - 1) * na + ia] = 0.;
                    b[(ib * n + 0) * na + ia] += a[(ib * n + 1) * na + ia];
                    b[(ib * n + n / 2) * na + ia] += +a[(ib * n + n / 2) * na + ia] - a[(ib * n + n / 2 + 1) * na + ia];
                    b[(ib * n + n / 2 + 1) * na + ia] += -a[(ib * n + n / 2 + 1) * na + ia] - a[(ib * n + n / 2) * na + ia];
                }
        } else {
            for (ia = 0; ia < na; ++ia) {
                b[(ib * n + n - 1) * na + ia] = a[(ib * n + 0) * na + ia];
                b[(ib * n + 0) * na + ia] += a[(ib * n + n - 1) * na + ia];
            }
        }
        break;
      case R2R_REDFT00:
        isL1 = isR1 = 1;
        goto mirrors_rev;
      case R2R_REDFT01:
        isL1 = 1;
        goto mirrors_rev;
      case R2R_REDFT10:
        isL0 = isR0 = 1;
        goto mirrors_rev;
      case R2R_REDFT11:
        isL0 = 1;
        isR0 = -1;
        goto mirrors_rev;
      case R2R_RODFT00:
        goto mirrors_rev;
      case R2R_RODFT01:
        isR1 = 1;
        goto mirrors_rev;
      case R2R_RODFT10:
        isL0 = isR0 = -1;
        goto mirrors_rev;
      case R2R_RODFT11:
        isL0 = -1;
        isR0 = 1;
        goto mirrors_rev;
      mirrors_rev:
        for (ia = 0; ia < na; ++ia)
            b[(ib * n + n - 1) * na + ia] = isR0 * a[(ib * n + n - 1) * na + ia] + (n > 1 ? isR1 * a[(ib * n + n - 2) * na + ia] : 0);
        for (ia = 0; ia < na; ++ia)
            b[(ib * n) * na + ia] += isL0 * a[(ib * n) * na + ia] + (n > 1 ? isL1 * a[(ib * n + 1) * na + ia] : 0);
    }

    // Now process main body in reverse order to eliminate forward loop-carried dependence
    for (i = n - 2; i >= 0; --i)
        for (ia = 0; ia < na; ++ia)
            b[(ib * n + i) * na + ia] = a[(ib * n + i + 1) * na + ia];

    // Accumulation now proceeds forward but does not interfere due to prior separation
    for (i = 1; i < n; ++i)
        for (ia = 0; ia < na; ++ia)
            b[(ib * n + i) * na + ia] += a[(ib * n + i - 1) * na + ia];
}
}
