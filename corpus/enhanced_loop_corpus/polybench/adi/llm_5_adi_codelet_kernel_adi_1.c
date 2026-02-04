#include <stdio.h>

#include <inttypes.h>

extern int tsteps;
extern int n;
extern double u[1000][1000];
extern double v[1000][1000];
extern double p[1000][1000];
extern double q[1000][1000];
extern int t;
extern int i;
extern int j;
extern double a;
extern double b;
extern double c;
extern double d;
extern double e;
extern double f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (t = 1; t <= tsteps; t++) {
    for (i = 1; i < n - 1; i++) {
        v[0][i] = 1.;
        p[i][0] = 0.;
        q[i][0] = v[0][i];
        for (j = 1; j < n - 1; j++) {
            if (p[i][j - 1] == 0.0) continue;
            p[i][j] = -c / (a * p[i][j - 1] + b);
            q[i][j] = (-d * u[j][i - 1] + (1. + 2. * d) * u[j][i] - f * u[j][i + 1] - a * q[i][j - 1]) / (a * p[i][j - 1] + b);
        }
        v[n - 1][i] = 1.;
        for (j = n - 2; j >= 1; j--) {
            v[j][i] = p[i][j] * v[j + 1][i] + q[i][j];
        }
    }
    for (i = 1; i < n - 1; i++) {
        u[i][0] = 1.;
        p[i][0] = 0.;
        q[i][0] = u[i][0];
        for (j = 1; j < n - 1; j++) {
            if (p[i][j - 1] != 0.0) {
                p[i][j] = -f / (d * p[i][j - 1] + e);
                q[i][j] = (-a * v[i - 1][j] + (1. + 2. * a) * v[i][j] - c * v[i + 1][j] - d * q[i][j - 1]) / (d * p[i][j - 1] + e);
            } else {
                p[i][j] = 0.0;
                q[i][j] = (-a * v[i - 1][j] + (1. + 2. * a) * v[i][j] - c * v[i + 1][j]) / e;
            }
        }
        u[i][n - 1] = 1.;
        for (j = n - 2; j >= 1; j--) {
            u[i][j] = p[i][j] * u[i][j + 1] + q[i][j];
        }
    }
}
}
