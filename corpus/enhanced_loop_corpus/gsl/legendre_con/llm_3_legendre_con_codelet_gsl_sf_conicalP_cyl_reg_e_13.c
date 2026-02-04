#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int m;
extern  double lambda;
extern  double xi;
extern double Pkp1;
extern double Pk;
extern double Pkm1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *P_arr = (double*)malloc((m + 3) * sizeof(double));
    int base_idx = m + 1;
    for (int idx = 0; idx <= m; idx++) {
        k = m - idx;
        double d = (k + 0.5) * (k + 0.5) + lambda * lambda;
        int curr = base_idx - idx;
        int next1 = curr + 1;
        int next2 = curr + 2;
        P_arr[curr - 1] = 2. * k * xi * P_arr[curr] - d * P_arr[next1];
        P_arr[next1] = P_arr[curr];
        P_arr[next2] = P_arr[next1];
    }
    Pkm1 = P_arr[base_idx - m - 1];
    Pk = P_arr[base_idx - m];
    Pkp1 = P_arr[base_idx - m + 1];
    free(P_arr);
}
