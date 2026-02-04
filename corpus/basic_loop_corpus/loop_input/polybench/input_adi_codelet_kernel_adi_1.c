#include <stdio.h>
#include <inttypes.h>

int tsteps = 50;
int n = 512;

double u[1000][1000];
double v[1000][1000];
double p[1000][1000];
double q[1000][1000];

int t;
int i;
int j;

double a = 0.1;
double b = 0.4;
double c = 0.2;
double d = 0.3;
double e = 0.5;
double f = 0.25;

void init_vars() {
    for (int ii = 0; ii < 1000; ++ii) {
        for (int jj = 0; jj < 1000; ++jj) {
            u[ii][jj] = (ii + jj) * 0.01;
            v[ii][jj] = (ii - jj) * 0.01;
            p[ii][jj] = 0.0;
            q[ii][jj] = 0.0;
        }
    }

    t = 0;
    i = 0;
    j = 0;
}