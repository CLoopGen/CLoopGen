#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT i;
extern INT n;
extern INT nb;
extern R *w;
extern R *W;
extern E nbf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < n; ++i) {
    INT src_idx_even = 2 * i;
    INT src_idx_odd = src_idx_even + 1;
    INT dst_forward_even = src_idx_even;
    INT dst_forward_odd = src_idx_odd;
    INT dst_mirror_even = 2 * (nb - i);
    INT dst_mirror_odd = dst_mirror_even + 1;

    E temp_even = w[src_idx_even] / nbf;
    E temp_odd = w[src_idx_odd] / nbf;

    W[dst_forward_even] = temp_even;
    W[dst_mirror_even] = temp_even;
    W[dst_forward_odd] = temp_odd;
    W[dst_mirror_odd] = temp_odd;
}
}
