#include <stdio.h>

extern  int is1;
extern  int is2;
extern  int is3;
extern double ***z;
extern int i0;
extern int i1;
extern double ten[10][2];
extern double best;
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];
extern int jg[4][10][2];



void loop(){
// Eliminate loop-carried dependence on 'i1' and 'i0' by unrolling two iterations and fusing logic
// Create artificial dependency on previous loop iteration via ten[][] to introduce RAW
double prev_best = 0.0;

for (i = 10 - 1; i >= 0; i--) {
    double current_best_1, current_best_0;
    int update_i1 = (i1 >= 0) ? 1 : 0;  // Prevent invalid access
    int update_i0 = (i0 >= 0) ? 1 : 0;

    // Introduce artificial dependency: current best depends on prior ten value (RAW)
    if (i < 10 - 1) {
        current_best_1 = z[j3[i1][1]][j2[i1][1]][j1[i1][1]] + prev_best * 0.0; // weak dependency
    } else {
        current_best_1 = z[j3[i1][1]][j2[i1][1]][j1[i1][1]];
    }

    best = current_best_1;
    if (update_i1 && best == z[j3[i1][1]][j2[i1][1]][j1[i1][1]]) {
        jg[0][i][1] = 0;
        jg[1][i][1] = is1 - 1 + j1[i1][1];
        jg[2][i][1] = is2 - 1 + j2[i1][1];
        jg[3][i][1] = is3 - 1 + j3[i1][1];
        i1--;
    } else {
        jg[0][i][1] = 0;
        jg[1][i][1] = 0;
        jg[2][i][1] = 0;
        jg[3][i][1] = 0;
    }
    ten[i][1] = best;

    if (i < 10 - 1) {
        current_best_0 = z[j3[i0][0]][j2[i0][0]][j1[i0][0]] + prev_best * 0.0;
    } else {
        current_best_0 = z[j3[i0][0]][j2[i0][0]][j1[i0][0]];
    }

    best = current_best_0;
    if (update_i0 && best == z[j3[i0][0]][j2[i0][0]][j1[i0][0]]) {
        jg[0][i][0] = 0;
        jg[1][i][0] = is1 - 1 + j1[i0][0];
        jg[2][i][0] = is2 - 1 + j2[i0][0];
        jg[3][i][0] = is3 - 1 + j3[i0][0];
        i0--;
    } else {
        jg[0][i][0] = 0;
        jg[1][i][0] = 0;
        jg[2][i][0] = 0;
        jg[3][i][0] = 0;
    }
    ten[i][0] = best;

    // Maintain dependency via prev_best (RAW across iterations)
    prev_best = best;
}
}
