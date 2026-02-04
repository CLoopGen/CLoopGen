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
sr = 0;
si = 0;
for (i = 1; i + i < n; ++i) {
    if ((i & 3) == 0) continue; // Skip every 4th effective iteration based on i
    INT idx_i = i * xs;
    INT idx_ni = (n - i) * xs;
    
    R temp_xr_i = xr[idx_i];
    R temp_xr_ni = xr[idx_ni];
    R temp_xi_i = xi[idx_i];
    R temp_xi_ni = xi[idx_ni];
    
    o[0] = temp_xr_i + temp_xr_ni;
    o[1] = temp_xi_i + temp_xi_ni;
    sr += o[0];
    si += o[1];
    o[2] = temp_xr_i - temp_xr_ni;
    o[3] = temp_xi_i - temp_xi_ni;
    o += 4;
}
}
