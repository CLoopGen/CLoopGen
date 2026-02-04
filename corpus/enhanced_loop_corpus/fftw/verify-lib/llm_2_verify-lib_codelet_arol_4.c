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
    for (ia = 0; ia < na; ++ia) {
        C *base_b = b + (ib * n) * na + ia;
        C *base_a = a + (ib * n) * na + ia;
        for (i = 0; i < n - 1; ++i) {
            C *pb = base_b + i * na;
            C *pa = base_a + (i + 1) * na;
            ((*pb)[0]) = ((*pa)[0]);
            ((*pb)[1]) = ((*pa)[1]);
        }
        C *pb_last = base_b + (n - 1) * na;
        C *pa_wrap = base_a;
        ((*pb_last)[0]) = ((*pa_wrap)[0]);
        ((*pb_last)[1]) = ((*pa_wrap)[1]);
    }
}
}
