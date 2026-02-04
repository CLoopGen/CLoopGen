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
    ftnlen stride = 1;
    for (i = 0; i < n; i += stride) {
        nc = rnp[i];
        if (ll < nc)
            nc = ll;
        ll -= nc;
        rp = rpp[i];
        for (ftnlen j = 0; j < nc; ++j) {
            lp[j] = rp[j];
        }
        lp += nc;
    }
    if (ll > 0) {
        for (ftnlen j = 0; j < ll; ++j) {
            *lp++ = '\0';
        }
    }
}
