#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DWTPlane {
    int width;
    int height;
    int stride;
    uint8_t *buf;
    uint8_t *buf_base;
    uint8_t *tmp;
} DWTPlane;

typedef struct SubBand {
    int level;
    int orientation;
    int stride;
    int width;
    int height;
    int pshift;
    int quant;
    uint8_t *ibuf;
    struct SubBand *parent;
    unsigned int length;
    const uint8_t *coeff_data;
} SubBand;

typedef struct Plane {
    DWTPlane idwt;
    int width;
    int height;
    ptrdiff_t stride;
    uint8_t xblen;
    uint8_t yblen;
    uint8_t xbsep;
    uint8_t ybsep;
    uint8_t xoffset;
    uint8_t yoffset;
    SubBand band[5][4];
} Plane;

uint8_t *src[5];
int x;
int y;
Plane *p;
uint8_t **ref_hpel;
int i;

#define DATA_SIZE (16 << 20)

static uint8_t *data_pool;
static uint8_t **ref_hpel_storage;
static Plane *plane_storage;

void init_vars() {
    data_pool = (uint8_t*)calloc(DATA_SIZE, sizeof(uint8_t));
    if (!data_pool) exit(1);

    ref_hpel_storage = (uint8_t**)calloc(5, sizeof(uint8_t*));
    if (!ref_hpel_storage) exit(1);

    for (int idx = 0; idx < 5; idx++) {
        ref_hpel_storage[idx] = data_pool + idx * (DATA_SIZE / 5);
    }

    plane_storage = (Plane*)calloc(1, sizeof(Plane));
    if (!plane_storage) exit(1);

    plane_storage->stride = (DATA_SIZE / 5); 

    x = 16;
    y = 4;

    src[0] = NULL;
    src[1] = NULL;
    src[2] = NULL;
    src[3] = NULL;
    src[4] = NULL;

    ref_hpel = ref_hpel_storage;
    p = plane_storage;
}