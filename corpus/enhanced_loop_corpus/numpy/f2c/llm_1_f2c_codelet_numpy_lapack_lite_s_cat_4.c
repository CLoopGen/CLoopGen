#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int ftnlen;

extern char *lp;
extern char *rpp[];
extern ftnlen rnp[];
extern ftnlen ll;
extern ftnlen i;
extern ftnlen nc;
extern char *rp;
extern ftnlen n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; ++i) {
        nc = (rnp[i] < ll) ? rnp[i] : ll;
        ll -= nc;
        for (ftnlen k = 0; k < nc; ++k) {
            *lp++ = rpp[i][k];
        }
    }
}
