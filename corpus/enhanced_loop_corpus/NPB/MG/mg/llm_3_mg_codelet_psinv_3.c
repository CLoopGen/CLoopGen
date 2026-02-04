#include <stdio.h>

extern double ***r;
extern double ***u;
extern int n1;
extern int n2;
extern int n3;
extern double c[4];
extern int i3;
extern int i2;
extern int i1;
extern double r1[1037];
extern double r2[1037];



void loop(){
for (i3 = 1; i3 < n3 - 1; i3++) {
    for (i2 = 1; i2 < n2 - 1; i2++) {
        for (i1 = 0; i1 < n1; i1++) {
            int idx = i1;
            r1[idx] = r[i3][i2 - 1][idx] + r[i3][i2 + 1][idx] + r[i3 - 1][i2][idx] + r[i3 + 1][i2][idx];
            r2[idx] = r[i3 - 1][i2 - 1][idx] + r[i3 - 1][i2 + 1][idx] + r[i3 + 1][i2 - 1][idx] + r[i3 + 1][i2 + 1][idx];
        }
        for (i1 = 1; i1 < n1 - 1; i1++) {
            int prev = i1 - 1, curr = i1, next = i1 + 1;
            u[i3][i2][curr] = u[i3][i2][curr] + c[0] * r[i3][i2][curr] +
                              c[1] * (r[i3][i2][prev] + r[i3][i2][next] + r1[curr]) +
                              c[2] * (r2[curr] + r1[prev] + r1[next]);
        }
    }
}
}
