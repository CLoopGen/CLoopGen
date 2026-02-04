#include <stdio.h>
#include <inttypes.h>

typedef short word;
typedef long longword;

word Nc = 8;
word *dp;
word *d;
word *dpp;
word *e;
int k;
longword ltmp;

word dp_array[48];
word d_array[40];
word dpp_array[40];
word e_array[40];

void init_vars() {
    dp = dp_array + Nc; // adjust so that dp[k - Nc] for k=0 accesses dp_array[0]
    d = d_array;
    dpp = dpp_array;
    e = e_array;

    for (int i = 0; i < 48; i++) {
        dp_array[i] = (i * 17) % 1000;
    }
    for (int i = 0; i < 40; i++) {
        d_array[i] = (i * 31) % 2000;
    }
}