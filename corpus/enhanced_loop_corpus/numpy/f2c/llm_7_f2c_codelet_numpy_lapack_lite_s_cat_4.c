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
    ftnlen local_ll = ll;
    for (i = 0; i < n; ++i) {
        ftnlen nc_val = rnp[i];
        ftnlen copy_count = (nc_val < local_ll) ? nc_val : local_ll;
        rp = rpp[i];
        for (ftnlen k = copy_count - 1; k >= 0; --k) {
            lp[k] = rp[k];
        }
        lp += copy_count;
        local_ll -= copy_count;
    }
    ll = local_ll;
}
