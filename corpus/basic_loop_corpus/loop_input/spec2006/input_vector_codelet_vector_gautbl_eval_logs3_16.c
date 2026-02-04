#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int int32;
typedef float float32;
typedef double float64;

typedef struct {
    int32 n_gau;
    int32 veclen;
    float32 **mean;
    float32 **var;
    float32 *lrd;
    float64 distfloor;
} vector_gautbl_t;

vector_gautbl_t *gautbl;
int32 offset;
float32 *x;
int32 *score;
int32 i;
int32 r;
float64 f;
int32 end;
int32 veclen;
float32 *m1;
float32 *m2;
float32 *v1;
float32 *v2;
float64 dval1;
float64 dval2;
float64 diff1;
float64 diff2;

void init_vars() {
    veclen = 128;
    gautbl = (vector_gautbl_t*)malloc(sizeof(vector_gautbl_t));
    gautbl->veclen = veclen;
    gautbl->n_gau = 2000;
    end = gautbl->n_gau;
    offset = 0;
    gautbl->distfloor = -100.0;
    f = 10.0;

    gautbl->mean = (float32**)malloc(end * sizeof(float32*));
    gautbl->var = (float32**)malloc(end * sizeof(float32*));
    gautbl->lrd = (float32*)malloc(end * sizeof(float32));

    for (int32 idx = 0; idx < end; idx++) {
        gautbl->mean[idx] = (float32*)malloc(veclen * sizeof(float32));
        gautbl->var[idx] = (float32*)malloc(veclen * sizeof(float32));
        gautbl->lrd[idx] = 5.0 + (idx % 10);
        for (int32 j = 0; j < veclen; j++) {
            gautbl->mean[idx][j] = (float32)(1.0 + (idx + j) % 10) / 10.0;
            gautbl->var[idx][j] = (float32)(1.0 + ((idx + j) % 5)) / 5.0;
        }
    }

    x = (float32*)malloc(veclen * sizeof(float32));
    for (int32 j = 0; j < veclen; j++) {
        x[j] = (float32)(j % 10) / 10.0;
    }

    score = (int32*)malloc(end * sizeof(int32));
    for (int32 idx = 0; idx < end; idx++) {
        score[idx] = 0;
    }

    m1 = NULL;
    m2 = NULL;
    v1 = NULL;
    v2 = NULL;
    dval1 = 0.0;
    dval2 = 0.0;
    diff1 = 0.0;
    diff2 = 0.0;
}