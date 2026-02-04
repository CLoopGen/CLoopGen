#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT n;
extern  R *xr;
extern  R *xi;
extern INT xs;
extern E *o;
extern INT i;
extern E sr;
extern E si;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
R acc_sr = sr;
R acc_si = si;
for (i = 1; i + i < n; ++i) {
    INT idx1 = i * xs;
    INT idx2 = (n - i) * xs;
    R sum_r = xr[idx1] + xr[idx2];
    R sum_i = xi[idx1] + xi[idx2];
    R diff_r = xr[idx1] - xr[idx2];
    R diff_i = xi[idx1] - xi[idx2];
    o[0] = sum_r;
    o[1] = sum_i;
    o[2] = diff_r;
    o[3] = diff_i;
    acc_sr += sum_r;
    acc_si += sum_i;
    o += 4;
}
sr = acc_sr;
si = acc_si;
}
