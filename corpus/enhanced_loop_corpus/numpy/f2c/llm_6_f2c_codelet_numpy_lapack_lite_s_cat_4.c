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
    ftnlen temp_nc;
    for (i = 0; i < n; ++i) {
        temp_nc = (rnp[i] < ll) ? rnp[i] : ll;
        rp = rpp[i];
        for (ftnlen j = 0; j < temp_nc; ++j) {
            *lp++ = rp[j];
        }
        ll -= temp_nc;
    }
}
