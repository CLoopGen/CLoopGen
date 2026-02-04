#include <stdio.h>
#include <stdlib.h>

int is1 = 10;
int is2 = 10;
int is3 = 10;
double ***z;
int i0 = 9;
int i1 = 9;
double ten[10][2];
double best;
int i;
int j1[10][2] = {{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1}};
int j2[10][2] = {{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1}};
int j3[10][2] = {{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1}};
int jg[4][10][2];

void init_vars() {
    const int Nx = 200;
    const int Ny = 200;
    const int Nz = 64;

    z = (double***)malloc(Nx * sizeof(double**));
    for (int x = 0; x < Nx; x++) {
        z[x] = (double**)malloc(Ny * sizeof(double*));
        for (int y = 0; y < Ny; y++) {
            z[x][y] = (double*)malloc(Nz * sizeof(double));
            for (int z_idx = 0; z_idx < Nz; z_idx++) {
                z[x][y][z_idx] = (double)(x + y + z_idx);
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            j1[i][j] = (i + j) % 5 + 1;
            j2[i][j] = (i + j + 1) % 5 + 1;
            j3[i][j] = (i + j + 2) % 5 + 1;
        }
    }

    i0 = 9;
    i1 = 9;
    is1 = 10;
    is2 = 10;
    is3 = 10;

    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 2; c++) {
                jg[a][b][c] = 0;
            }
        }
    }

    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 2; b++) {
            ten[a][b] = 0.0;
        }
    }

    best = 0.0;
}