#include <stdio.h>

double a[65536];
int colidx[65536];
int rowstr[8192];
int arow[65536];
int acol[65536];
double aelt[65536];

int firstrow = 1;
int nnza = 65536;
int j;
int nza;
int k;

void init_vars() {
    for (int i = 0; i < 65536; i++) {
        a[i] = 0.0;
        colidx[i] = 0;
        arow[i] = (i % 8190) + 1;
        acol[i] = (i % 8190) + 1;
        aelt[i] = (double)(i + 1) * 0.5;
    }
    for (int i = 0; i < 8192; i++) {
        rowstr[i] = i * 8;
    }
}