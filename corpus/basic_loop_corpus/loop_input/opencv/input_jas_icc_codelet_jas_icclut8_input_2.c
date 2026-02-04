#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint_fast8_t jas_iccuint8_t;
typedef int_fast32_t jas_iccsint32_t;
typedef uint_fast16_t jas_iccuint16_t;

typedef struct {
    jas_iccuint8_t numinchans;
    jas_iccuint8_t numoutchans;
    jas_iccsint32_t e[3][3];
    jas_iccuint8_t clutlen;
    jas_iccuint8_t *clut;
    jas_iccuint16_t numintabents;
    jas_iccuint8_t **intabs;
    jas_iccuint8_t *intabsbuf;
    jas_iccuint16_t numouttabents;
    jas_iccuint8_t **outtabs;
    jas_iccuint8_t *outtabsbuf;
} jas_icclut8_t;

int i;
jas_icclut8_t *lut8;

void init_vars() {
    const size_t data_size = 16777216; // ~16MB to target ~0.01s runtime
    lut8 = (jas_icclut8_t*)calloc(1, sizeof(jas_icclut8_t));

    lut8->numinchans = 4;
    lut8->numoutchans = 4;
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            lut8->e[r][c] = (r == c) ? 1 : 0;
    lut8->clutlen = 16;
    lut8->clut = (jas_iccuint8_t*)calloc(lut8->clutlen, sizeof(jas_iccuint8_t));
    lut8->numintabents = data_size / (lut8->numinchans * sizeof(jas_iccuint8_t));
    lut8->intabs = (jas_iccuint8_t**)calloc(lut8->numinchans, sizeof(jas_iccuint8_t*));
    lut8->intabsbuf = (jas_iccuint8_t*)calloc(data_size, sizeof(jas_iccuint8_t));
    lut8->numouttabents = 256;
    lut8->outtabs = (jas_iccuint8_t**)calloc(lut8->numoutchans, sizeof(jas_iccuint8_t*));
    lut8->outtabsbuf = (jas_iccuint8_t*)calloc(lut8->numoutchans * lut8->numouttabents, sizeof(jas_iccuint8_t));

    for (int c = 0; c < lut8->numoutchans; ++c)
        lut8->outtabs[c] = &lut8->outtabsbuf[c * lut8->numouttabents];
}