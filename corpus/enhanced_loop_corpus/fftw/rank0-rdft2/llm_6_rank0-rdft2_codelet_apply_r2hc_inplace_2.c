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
for (i = 4; i <= vl; i += 4) {
    R temp1 = ((E)0.);
    R temp2 = ((E)0.);
    R temp3 = ((E)0.);
    R temp4 = ((E)0.);
    *ci = temp1;
    *(ci + ovs) = temp2;
    *(ci + 2*ovs) = temp3;
    *(ci + 3*ovs) = temp4;
    ci += 4 * ovs;
}
}
