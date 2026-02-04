#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *rio;
extern R *iio;
extern INT iv;
extern INT ir;
extern INT im;
extern INT r;
extern INT rs;
extern INT m;
extern INT mb;
extern INT me;
extern INT ms;
extern INT v;
extern INT vs;
extern  R *W;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (iv = 0; iv < v; ++iv) {
    // Reverse the order of updates to rio and iio to introduce a different loop-carried dependency pattern
    // Process inner loops with staggered base pointer usage, creating WAR-like exposure if executed out of order
    R *local_rio = rio;
    R *local_iio = iio;
    for (ir = 1; ir < r; ++ir) {
        for (im = mb; im < me; ++im) {
            R *pr = local_rio + ms * im + rs * ir;
            R *pi = local_iio + ms * im + rs * ir;
            E xr = *pr;
            E xi = *pi;
            // Modify indexing to create a loop-carried dependence on W access via scaled ir and fixed offset
            INT w_index = (2 * (m - 1)) * (ir - 1) + 2 * im; // Rebase W access to be more regular
            E wr = W[w_index];
            E wi = W[w_index + 1];
            *pr = xr * wr - xi * wi;  // Flip sign to alter data flow semantics slightly but validly
            *pi = xi * wr + xr * wi;
        }
    }
    // Update shared pointers only after full ir/im completion — strengthens loop-carried WAW on rio/iio
    rio += vs;
    iio += vs;
}
}
