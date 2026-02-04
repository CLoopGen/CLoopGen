#include <stdio.h>

#define ARRAY_SIZE 1037

double ten[ARRAY_SIZE][2];
int j1[ARRAY_SIZE][2];
int j2[ARRAY_SIZE][2];
int j3[ARRAY_SIZE][2];
int m;
int ind;
double temp;
int i;
int j_temp;

void init_vars() {
    m = 1036; 
    ind = 0;
    
    for (int row = 0; row < ARRAY_SIZE; row++) {
        for (int col = 0; col < 2; col++) {
            ten[row][col] = (double)(ARRAY_SIZE - row);
            j1[row][col] = row * 2 + col;
            j2[row][col] = row * 3 + col;
            j3[row][col] = row * 5 + col;
        }
    }
}