#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *b;
extern C *a;
extern int n;
extern int nb;
extern int na;
extern int i;
extern int ib;
extern int ia;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ib = 0; ib < nb; ++ib) {
    for (i = 0; i < n - 1; i += 2) { // Modified trip count and stride
        for (ia = 0; ia < na; ++ia) {
            if (i + 1 < n - 1) { // Guard for safe access
                C *pb0 = b + (ib * n + i) * na + ia;
                C *pa0 = a + (ib * n + i + 1) * na + ia;
                C *pb1 = b + (ib * n + i + 1) * na + ia;
                C *pa1 = a + (ib * n + i + 2) * na + ia;

                ((*pb0)[0]) = ((*pa0)[0]);
                ((*pb0)[1]) = ((*pa0)[1]);
                ((*pb1)[0]) = ((*pa1)[0]);
                ((*pb1)[1]) = ((*pa1)[1]);
            }
        }
    }
    // Reduced frequency: execute wrap-around copy only once per outer loop
    for (ia = 0; ia < na; ++ia) {
        C *pb = b + (ib * n + n - 1) * na + ia;
        C *pa = a + ib * n * na + ia;
        ((*pb)[0]) = ((*pa)[0]);
        ((*pb)[1]) = ((*pa)[1]);
    }
}
}
