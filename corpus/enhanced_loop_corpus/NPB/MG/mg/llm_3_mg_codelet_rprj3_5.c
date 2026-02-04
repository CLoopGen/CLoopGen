#include <stdio.h>

extern double ***r;
extern double ***s;
extern int m1j;
extern int m2j;
extern int m3j;
extern int j3;
extern int j2;
extern int j1;
extern int i3;
extern int i2;
extern int i1;
extern int d1;
extern int d2;
extern int d3;
extern double x1[1037];
extern double y1[1037];
extern double x2;
extern double y2;



void loop(){
    // Variant 2: Memory Access Pattern Modification - Strided Access with Index Arrays
    // Use indirect indexing through precomputed index arrays to simulate strided memory access
    // This variant introduces indirection to abstract memory layout, potentially improving
    // cache behavior under certain data alignments or enabling future vectorization.

    int idx_r1[4], idx_r2[4], idx_r3[4], idx_r4[4], idx_r5[4];
    int idx_s;

    for (j3 = 1; j3 < m3j - 1; j3++) {
        i3 = 2 * j3 - d3;
        for (j2 = 1; j2 < m2j - 1; j2++) {
            i2 = 2 * j2 - d2;
            // Precompute stride indices used repeatedly
            idx_r1[0] = i3 + 1; idx_r1[1] = i3 + 1; idx_r1[2] = i3;     idx_r1[3] = i3 + 2;
            idx_r2[0] = i2;     idx_r2[1] = i2 + 2; idx_r2[2] = i2 + 1; idx_r2[3] = i2 + 1;
            idx_r3[0] = i3;     idx_r3[1] = i3 + 2; idx_r3[2] = i3;     idx_r3[3] = i3 + 2;
            idx_r4[0] = i2;     idx_r4[1] = i2;     idx_r4[2] = i2 + 2; idx_r4[3] = i2 + 2;
            idx_r5[0] = i3 + 1; idx_r5[1] = i3 + 1; idx_r5[2] = i3;     idx_r5[3] = i3 + 2;

            for (j1 = 1; j1 < m1j; j1++) {
                i1 = 2 * j1 - d1;
                x1[i1] = r[idx_r1[0]][idx_r2[0]][i1] + r[idx_r1[1]][idx_r2[1]][i1] +
                         r[idx_r1[2]][idx_r2[2]][i1] + r[idx_r1[3]][idx_r2[3]][i1];
                y1[i1] = r[idx_r3[0]][idx_r4[0]][i1] + r[idx_r3[1]][idx_r4[1]][i1] +
                         r[idx_r3[2]][idx_r4[2]][i1] + r[idx_r3[3]][idx_r4[3]][i1];
            }
            for (j1 = 1; j1 < m1j - 1; j1++) {
                i1 = 2 * j1 - d1;
                y2 = r[idx_r3[0]][idx_r4[0]][i1 + 1] + r[idx_r3[1]][idx_r4[1]][i1 + 1] +
                     r[idx_r3[2]][idx_r4[2]][i1 + 1] + r[idx_r3[3]][idx_r4[3]][i1 + 1];
                x2 = r[idx_r1[0]][idx_r2[0]][i1 + 1] + r[idx_r1[1]][idx_r2[1]][i1 + 1] +
                     r[idx_r5[2]][i2 + 1][i1 + 1] + r[idx_r5[3]][i2 + 1][i1 + 1];
                idx_s = j3 * m2j * m1j + j2 * m1j + j1; // Linearized index for potential extension
                s[j3][j2][j1] = 0.5 * r[i3 + 1][i2 + 1][i1 + 1] +
                                0.25 * (r[i3 + 1][i2 + 1][i1] + r[i3 + 1][i2 + 1][i1 + 2] + x2) +
                                0.125 * (x1[i1] + x1[i1 + 2] + y2) +
                                0.0625 * (y1[i1] + y1[i1 + 2]);
            }
        }
    }
}
