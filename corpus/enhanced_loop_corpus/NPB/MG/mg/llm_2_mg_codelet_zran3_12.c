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
for (i = 0; i < 10; i++) {
    int idx = 9 - i; // Reverse iteration via index remapping (consecutive forward access)
    best = z[j3[i1][1]][j2[i1][1]][j1[i1][1]];
    if (best == z[j3[i1][1]][j2[i1][1]][j1[i1][1]]) {
        jg[0][idx][1] = 0;
        jg[1][idx][1] = is1 - 1 + j1[i1][1];
        jg[2][idx][1] = is2 - 1 + j2[i1][1];
        jg[3][idx][1] = is3 - 1 + j3[i1][1];
        i1--;
    } else {
        jg[0][idx][1] = 0;
        jg[1][idx][1] = 0;
        jg[2][idx][1] = 0;
        jg[3][idx][1] = 0;
    }
    ten[idx][1] = best;
    best = z[j3[i0][0]][j2[i0][0]][j1[i0][0]];
    if (best == z[j3[i0][0]][j2[i0][0]][j1[i0][0]]) {
        jg[0][idx][0] = 0;
        jg[1][idx][0] = is1 - 1 + j1[i0][0];
        jg[2][idx][0] = is2 - 1 + j2[i0][0];
        jg[3][idx][0] = is3 - 1 + j3[i0][0];
        i0--;
    } else {
        jg[0][idx][0] = 0;
        jg[1][idx][0] = 0;
        jg[2][idx][0] = 0;
        jg[3][idx][0] = 0;
    }
    ten[idx][0] = best;
}
}
