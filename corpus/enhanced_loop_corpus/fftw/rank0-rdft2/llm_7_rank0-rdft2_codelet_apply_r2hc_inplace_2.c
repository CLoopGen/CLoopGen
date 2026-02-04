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
R prev_val = ((E)0.);
for (i = 4; i <= vl; i += 4) {
    *ci = prev_val;
    prev_val += ((E)1.); 
    ci += ovs;
    *ci = prev_val;
    prev_val += ((E)1.);
    ci += ovs;
    *ci = prev_val;
    prev_val += ((E)1.);
    ci += ovs;
    *ci = prev_val;
    prev_val += ((E)1.);
    ci += ovs;
}
}
