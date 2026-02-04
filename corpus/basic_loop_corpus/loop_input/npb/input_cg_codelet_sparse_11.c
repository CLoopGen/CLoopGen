#include <stdio.h>

int rowstr[262144];
int arow[131073];
int firstrow = 1;
int nnza = 131072;
int j;
int nza;

void init_vars() {
    for (int i = 1; i <= nnza; i++) {
        arow[i] = i + firstrow - 1;
    }
    for (int i = 1; i <= nnza + 1; i++) {
        rowstr[i] = 0;
    }
}