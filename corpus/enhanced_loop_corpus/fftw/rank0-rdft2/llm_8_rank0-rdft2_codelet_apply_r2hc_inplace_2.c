#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *ci;
extern INT i;
extern INT vl;
extern INT ovs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4; i <= vl; i += 8) {
    *ci = ((E)0.);
    ci[ovs] = ((E)1.);
    ci[2*ovs] = ((E)2.);
    ci[3*ovs] = ((E)3.);
    ci += 4*ovs;
    *ci = ((E)4.);
    ci[ovs] = ((E)5.);
    ci[2*ovs] = ((E)6.);
    ci[3*ovs] = ((E)7.);
    ci += 4*ovs;
}
}
