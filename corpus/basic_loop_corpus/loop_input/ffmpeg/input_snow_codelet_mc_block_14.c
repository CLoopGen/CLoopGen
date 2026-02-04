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

static Plane p_instance;
Plane *p = &p_instance;

static uint8_t src_data[1 << 20]; // ~1MB of source data
uint8_t *src = src_data;

static int16_t tmpI_data[1 << 19]; // 512KB for tmpI (each int16_t is 2 bytes)
int16_t *tmpI = tmpI_data;

static uint8_t tmp2_data[1 << 18]; // 256KB for tmp2
uint8_t *tmp2 = tmp2_data;

int stride = 64;
int b_w = 32;
int b_h = 256;
int x;
int y;

void init_vars() {
    p = &p_instance;
    p->fast_mc = 1;
    p->hcoeff[0] = 20;
    p->hcoeff[1] = -5;
    p->hcoeff[2] = 1;
    p->hcoeff[3] = 0;
    p->htaps = 4;
    p->diag_mc = 0;
    p->last_htaps = 4;
    p->last_diag_mc = 0;
    p->width = b_w;
    p->height = b_h;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            p->band[i][j].level = 0;
            p->band[i][j].stride = 64;
            p->band[i][j].width = b_w;
            p->band[i][j].height = b_h;
            p->band[i][j].qlog = 1;
            p->band[i][j].buf = NULL;
            p->band[i][j].ibuf = NULL;
            p->band[i][j].buf_x_offset = 0;
            p->band[i][j].buf_y_offset = 0;
            p->band[i][j].stride_line = 64;
            p->band[i][j].x_coeff = NULL;
            p->band[i][j].parent = NULL;
            for (int k = 0; k < 519; k++)
                for (int l = 0; l < 32; l++)
                    p->band[i][j].state[k][l] = 0;
        }
    }

    src = src_data;
    tmpI = tmpI_data;
    tmp2 = tmp2_data;

    for (int i = 0; i < (1 << 20); i++)
        src_data[i] = (uint8_t)(i % 256);

    for (int i = 0; i < (1 << 19); i++)
        tmpI_data[i] = 0;

    for (int i = 0; i < (1 << 18); i++)
        tmp2_data[i] = 0;

    stride = 64;
    b_w = 32;
    b_h = 256;
    x = 0;
    y = 0;
}