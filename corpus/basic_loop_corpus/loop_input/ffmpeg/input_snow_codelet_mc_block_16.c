#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int DWTELEM;
typedef short IDWTELEM;

typedef struct x_and_coeff {
    int16_t x;
    uint16_t coeff;
} x_and_coeff;

typedef struct SubBand {
    int level;
    int stride;
    int width;
    int height;
    int qlog;
    DWTELEM *buf;
    IDWTELEM *ibuf;
    int buf_x_offset;
    int buf_y_offset;
    int stride_line;
    x_and_coeff *x_coeff;
    struct SubBand *parent;
    uint8_t state[519][32];
} SubBand;

typedef struct Plane {
    int width;
    int height;
    SubBand band[8][4];
    int htaps;
    int8_t hcoeff[4];
    int diag_mc;
    int fast_mc;
    int last_htaps;
    int8_t last_hcoeff[4];
    int last_diag_mc;
} Plane;

Plane *p;
int b_w;
int b_h;
int x;
int y;
int16_t *tmpI;
uint8_t *tmp2;

void init_vars() {
    const int data_size_mb = 64;
    const int total_elements = (data_size_mb * 1024 * 1024) / sizeof(int16_t);
    const int estimated_b_w = 64;
    const int estimated_b_h = total_elements / estimated_b_w;

    b_w = estimated_b_w;
    b_h = estimated_b_h;

    p = (Plane*)calloc(1, sizeof(Plane));
    if (!p) exit(1);

    p->fast_mc = 0;
    p->hcoeff[0] = 20;
    p->hcoeff[1] = -5;
    p->hcoeff[2] = 1;
    p->hcoeff[3] = 1;

    tmpI = (int16_t*)calloc(total_elements, sizeof(int16_t));
    tmp2 = (uint8_t*)calloc(total_elements, sizeof(uint8_t));

    if (!tmpI || !tmp2) exit(1);
}