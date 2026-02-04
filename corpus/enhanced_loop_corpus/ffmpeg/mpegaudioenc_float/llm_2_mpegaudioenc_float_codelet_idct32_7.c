#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *tab;
extern int i;
extern int xr;
extern  int *xp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided and mirrored access (e.g., 30-i*4, i*4), reorganize accesses to be consecutive
    // by precomputing indices and accessing tab in increasing order.
    // Also unroll the loop partially for clarity and maintain correctness.

    int idxs1[4] = {0, 4, 8, 12};  // i*4 for i=0..3
    int idxs2[4] = {30, 26, 22, 18}; // 30-i*4
    int idxs3[4] = {2, 6, 10, 14};   // 2+i*4
    int idxs4[4] = {28, 24, 20, 16}; // 28-i*4
    int idxs5[4] = {1, 5, 9, 13};    // 1+i*4
    int idxs6[4] = {31, 27, 23, 19}; // 31-i*4
    int idxs7[4] = {3, 7, 11, 15};   // 3+i*4
    int idxs8[4] = {29, 25, 21, 17}; // 29-i*4

    for (i = 0; i < 4; i++) {
        xr = (((int64_t)tab[idxs2[i]] * (int64_t)xp[0]) >> 15);
        tab[idxs2[i]] = tab[idxs1[i]] - xr;
        tab[idxs1[i]] = tab[idxs1[i]] + xr;

        xr = (((int64_t)tab[idxs3[i]] * (int64_t)xp[1]) >> 15);
        tab[idxs3[i]] = tab[idxs4[i]] - xr;
        tab[idxs4[i]] = tab[idxs4[i]] + xr;

        xr = (((int64_t)tab[idxs6[i]] * (int64_t)xp[0]) >> 15);
        tab[idxs6[i]] = tab[idxs5[i]] - xr;
        tab[idxs5[i]] = tab[idxs5[i]] + xr;

        xr = (((int64_t)tab[idxs7[i]] * (int64_t)xp[1]) >> 15);
        tab[idxs7[i]] = tab[idxs8[i]] - xr;
        tab[idxs8[i]] = tab[idxs8[i]] + xr;

        xp += 2;
    }
}
