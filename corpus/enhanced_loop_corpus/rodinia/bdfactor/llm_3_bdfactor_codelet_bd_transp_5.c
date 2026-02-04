#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern int jj;
extern int l;
extern int lb;
extern int ub;
extern int lub;
extern int n1;
extern double **in_v;
extern int p;
extern int pp;
extern int lbi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0 , l = lub; i < (lub + 1) / 2; i++ , l--) {
    lbi = lb - i;
    // Change to indirect access using an index map (simulated with simple offset array)
    int *index_map = (int*)malloc((n1 + 1) * sizeof(int));
    for (int idx = 0; idx <= n1; idx++) {
        index_map[idx] = n1 - idx; // Reverse indexing pattern
    }
    for (j = l - lb , jj = 0 , p = ((-lbi) > (0) ? (-lbi) : (0)) , pp = ((l - ub) > (0) ? (l - ub) : (0)); j <= n1; j++ , jj++ , p++ , pp++) {
        int mapped_p = index_map[p];
        int mapped_j = index_map[j];
        int mapped_jj = index_map[jj];
        int mapped_pp = index_map[pp];
        if (mapped_p <= n1 && mapped_pp >= 0)
            in_v[l][mapped_pp] = in_v[i][mapped_p];
        if (mapped_j <= n1 && mapped_jj >= 0)
            in_v[i][mapped_jj] = in_v[l][mapped_j];
    }
    for (; p <= n1 - ((lbi) > (0) ? (lbi) : (0)); p++ , pp++) {
        int mapped_p = index_map[p];
        int mapped_pp = index_map[pp];
        if (mapped_p <= n1 && mapped_pp >= 0)
            in_v[l][mapped_pp] = in_v[i][mapped_p];
    }
    free(index_map);
}
}
