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
for (i = 10 - 1; i >= 0; i--) {
    for (int k = 1; k >= 0; k--) {
        best = z[j3[i1][k]][j2[i1][k]][j1[i1][k]];
        if (best == z[j3[i1][k]][j2[i1][k]][j1[i1][k]]) {
            jg[0][i][k] = 0;
            jg[1][i][k] = is1 - 1 + j1[i1][k];
            jg[2][i][k] = is2 - 1 + j2[i1][k];
            jg[3][i][k] = is3 - 1 + j3[i1][k];
            if (k == 1) i1 = i1 - 1;
        } else {
            jg[0][i][k] = 0;
            jg[1][i][k] = 0;
            jg[2][i][k] = 0;
            jg[3][i][k] = 0;
        }
        ten[i][k] = best;
    }
}
}
