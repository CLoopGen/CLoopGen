#include <stdio.h>
#include <inttypes.h>

int tmax = 200;
int nx = 800;
int ny = 600;

double ex[1000][1200];
double ey[1000][1200];
double hz[1000][1200];
double _fict_[500];

int t;
int i;
int j;

void init_vars() {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            ex[i][j] = 1.0;
            ey[i][j] = 1.0;
            hz[i][j] = 0.5;
        }
    }
    for (int t = 0; t < tmax; t++) {
        _fict_[t] = t * 0.1;
    }
}