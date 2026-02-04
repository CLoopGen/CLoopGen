#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double jas_cmreal_t;

typedef struct {
    jas_cmreal_t *data;
    int size;
} jas_cmshapmatlut_t;

typedef uint_fast32_t jas_iccuint32_t;

typedef uint_fast16_t jas_iccuint16_t;

typedef struct {
    jas_iccuint32_t numents;
    jas_iccuint16_t *ents;
} jas_icccurv_t;

jas_cmshapmatlut_t *lut;
jas_icccurv_t *curv;
int i;

void init_vars() {
    const int data_size = 16777216; // ~16M elements, leads to ~128MB total data (64MB per array), targets ~0.01s on modern CPUs

    lut = (jas_cmshapmatlut_t*)malloc(sizeof(jas_cmshapmatlut_t));
    curv = (jas_icccurv_t*)malloc(sizeof(jas_icccurv_t));

    lut->size = data_size;
    lut->data = (jas_cmreal_t*)malloc(data_size * sizeof(jas_cmreal_t));

    curv->numents = data_size;
    curv->ents = (jas_iccuint16_t*)malloc(data_size * sizeof(jas_iccuint16_t));

    for (int j = 0; j < data_size; ++j) {
        curv->ents[j] = (jas_iccuint16_t)(j % 65536);
    }

    for (int j = 0; j < data_size; ++j) {
        lut->data[j] = 0.0;
    }
}