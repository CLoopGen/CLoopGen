#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float float32;
typedef int int32;

float32 *mean;
float32 **data;
int32 n_vec;
int32 n_dim;
int32 i;
int32 j;

void init_vars() {
    n_dim = 1024; 
    n_vec = 256 * 1024 / sizeof(float32); 

    mean = (float32*)calloc(n_dim, sizeof(float32));

    data = (float32**)malloc(n_vec * sizeof(float32*));
    for (int i = 0; i < n_vec; i++) {
        data[i] = (float32*)malloc(n_dim * sizeof(float32));
        for (int j = 0; j < n_dim; j++) {
            data[i][j] = (float32)(i + j);
        }
    }

    i = 0;
    j = 0;
}