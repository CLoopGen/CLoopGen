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
    for (i = 0; i < n - 1; ++i)
        for (ia = 0; ia < na; ++ia) {
            C *pb = b + (ib * n + i) * na + ia;
            C *pa = a + (ib * n + i + 1) * na + ia;
            bench_real temp_re = (*pa)[0];
            bench_real temp_im = (*pa)[1];
            ((*pb)[0]) = temp_re;
            ((*pb)[1]) = temp_im;
        }
    for (ia = 0; ia < na; ++ia) {
        C *pb = b + (ib * n + n - 1) * na + ia;
        C *pa = a + ib * n * na + ia;
        bench_real temp_re = (*pa)[0];
        bench_real temp_im = (*pa)[1];
        ((*pb)[0]) = temp_re;
        ((*pb)[1]) = temp_im;
    }
}
}
