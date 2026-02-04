#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;
typedef float OPJ_FLOAT32;

OPJ_UINT32 nb_compo = 1024;
OPJ_INT32 k;
OPJ_UINT32 j;
OPJ_FLOAT32 sum;
OPJ_FLOAT32 u;
OPJ_UINT32 lStride;
OPJ_FLOAT32 *lCurrentPtr;
OPJ_FLOAT32 *lDestPtr;
OPJ_FLOAT32 *lTmpMatrix;
OPJ_FLOAT32 *lLineMatrix;
OPJ_FLOAT32 *lBeginPtr;
OPJ_FLOAT32 *lGeneratedData;

static OPJ_FLOAT32 *lCurrentPtr_data;
static OPJ_FLOAT32 *lDestPtr_data;
static OPJ_FLOAT32 *lLineMatrix_data;
static OPJ_FLOAT32 *lBeginPtr_data;
static OPJ_FLOAT32 *lGeneratedData_data;

void init_vars() {
    const size_t data_size = nb_compo * nb_compo * sizeof(OPJ_FLOAT32);
    const size_t vec_size = nb_compo * sizeof(OPJ_FLOAT32);

    lCurrentPtr_data = (OPJ_FLOAT32*)calloc(nb_compo, sizeof(OPJ_FLOAT32));
    lDestPtr_data = (OPJ_FLOAT32*)calloc(nb_compo, sizeof(OPJ_FLOAT32));
    lLineMatrix_data = (OPJ_FLOAT32*)calloc(nb_compo * nb_compo, sizeof(OPJ_FLOAT32));
    lBeginPtr_data = (OPJ_FLOAT32*)calloc(nb_compo, sizeof(OPJ_FLOAT32));
    lGeneratedData_data = (OPJ_FLOAT32*)calloc(nb_compo, sizeof(OPJ_FLOAT32));

    if (!lCurrentPtr_data || !lDestPtr_data || !lLineMatrix_data || 
        !lBeginPtr_data || !lGeneratedData_data) {
        exit(1);
    }

    for (size_t i = 0; i < nb_compo; ++i) {
        lDestPtr_data[i] = 1.0f + (OPJ_FLOAT32)(i % 7);
        lGeneratedData_data[i] = 10.0f + (OPJ_FLOAT32)(i % 5);
        lBeginPtr_data[i] = 0.0f;
    }

    for (size_t i = 0; i < nb_compo * nb_compo; ++i) {
        lLineMatrix_data[i] = 0.1f + (OPJ_FLOAT32)(i % 3);
    }

    for (size_t i = 0; i < nb_compo; ++i) {
        size_t idx = i * nb_compo + i;
        if (idx < nb_compo * nb_compo) {
            lLineMatrix_data[idx] = 2.0f;
        }
    }

    lStride = nb_compo;
    lDestPtr = lDestPtr_data + nb_compo - 1;
    lLineMatrix = lLineMatrix_data + (nb_compo - 1) * lStride + (nb_compo - 1);
    lBeginPtr = lBeginPtr_data + nb_compo - 1;
    lGeneratedData = lGeneratedData_data + nb_compo - 1;
}