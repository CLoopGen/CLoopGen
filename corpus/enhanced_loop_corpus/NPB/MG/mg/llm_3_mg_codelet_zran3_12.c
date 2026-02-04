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
// Strided memory access pattern: process elements in reverse with stride of 1 but unroll by 2 iterations
// Simulate strided-like traversal by accessing non-consecutive indices through arithmetic
for (i = 10 - 2; i >= 0; i -= 2) {
    // Process i+1 first (higher index), then i (lower index) to maintain logical order
    for (int s = 1; s >= 0; s--) {
        int curr = i + s;
        best = z[j3[i1][1]][j2[i1][1]][j1[i1][1]];
        if (best == z[j3[i1][1]][j2[i1][1]][j1[i1][1]]) {
            jg[0][curr][1] = 0;
            jg[1][curr][1] = is1 - 1 + j1[i1][1];
            jg[2][curr][1] = is2 - 1 + j2[i1][1];
            jg[3][curr][1] = is3 - 1 + j3[i1][1];
            i1--;
        } else {
            jg[0][curr][1] = 0;
            jg[1][curr][1] = 0;
            jg[2][curr][1] = 0;
            jg[3][curr][1] = 0;
        }
        ten[curr][1] = best;

        best = z[j3[i0][0]][j2[i0][0]][j1[i0][0]];
        if (best == z[j3[i0][0]][j2[i0][0]][j1[i0][0]]) {
            jg[0][curr][0] = 0;
            jg[1][curr][0] = is1 - 1 + j1[i0][0];
            jg[2][curr][0] = is2 - 1 + j2[i0][0];
            jg[3][curr][0] = is3 - 1 + j3[i0][0];
            i0--;
        } else {
            jg[0][curr][0] = 0;
            jg[1][curr][0] = 0;
            jg[2][curr][0] = 0;
            jg[3][curr][0] = 0;
        }
        ten[curr][0] = best;
    }
}
// Handle remaining element if original count was odd (though 10 is even, include for completeness)
if (i == -1) {
    int curr = 0;
    best = z[j3[i1][1]][j2[i1][1]][j1[i1][1]];
    if (best == z[j3[i1][1]][j2[i1][1]][j1[i1][1]]) {
        jg[0][curr][1] = 0;
        jg[1][curr][1] = is1 - 1 + j1[i1][1];
        jg[2][curr][1] = is2 - 1 + j2[i1][1];
        jg[3][curr][1] = is3 - 1 + j3[i1][1];
        i1--;
    } else {
        jg[0][curr][1] = 0;
        jg[1][curr][1] = 0;
        jg[2][curr][1] = 0;
        jg[3][curr][1] = 0;
    }
    ten[curr][1] = best;

    best = z[j3[i0][0]][j2[i0][0]][j1[i0][0]];
    if (best == z[j3[i0][0]][j2[i0][0]][j1[i0][0]]) {
        jg[0][curr][0] = 0;
        jg[1][curr][0] = is1 - 1 + j1[i0][0];
        jg[2][curr][0] = is2 - 1 + j2[i0][0];
        jg[3][curr][0] = is3 - 1 + j3[i0][0];
        i0--;
    } else {
        jg[0][curr][0] = 0;
        jg[1][curr][0] = 0;
        jg[2][curr][0] = 0;
        jg[3][curr][0] = 0;
    }
    ten[curr][0] = best;
}
}
