#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[2100][1900];
extern double s[1900];
extern double q[2100];
extern double p[1900];
extern double r[2100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    q[i] = 0.;
    for (j = 0; j < m; j += 2) {
        if (j + 1 < m) {
            s[j]   = s[j]   + r[i] * A[i][j];
            s[j+1] = s[j+1] + r[i] * A[i][j+1];
            q[i] = q[i] + A[i][j] * p[j] + A[i][j+1] * p[j+1];
        } else {
            s[j] = s[j] + r[i] * A[i][j];
            q[i] = q[i] + A[i][j] * p[j];
        }
    }
}
}
