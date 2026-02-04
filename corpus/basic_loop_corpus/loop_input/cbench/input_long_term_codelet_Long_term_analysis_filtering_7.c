#include <stdio.h>
#include <inttypes.h>

typedef short word;
typedef long longword;

word Nc = 10;
word *dp;
word *d;
word *dpp;
word *e;
int k;
longword ltmp;

word dp_array[50];
word d_array[40];
word dpp_array[40];
word e_array[40];

void init_vars() {
    dp = dp_array + Nc; // Adjust so that dp[k - Nc] is valid for k from 0 to 39
    d = d_array;
    dpp = dpp_array;
    e = e_array;

    for (int i = 0; i < 50; i++) {
        dp_array[i] = (word)(i * 3);
    }
    for (int i = 0; i < 40; i++) {
        d_array[i] = (word)(i * 5);
    }
}