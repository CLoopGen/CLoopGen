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

extern  uint8_t *src[5];
extern int x;
extern int y;
extern Plane *p;
extern uint8_t **ref_hpel;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        ptrdiff_t offset = y * p->stride + x;
        src[i] = ref_hpel[i] + offset;
    }
}
