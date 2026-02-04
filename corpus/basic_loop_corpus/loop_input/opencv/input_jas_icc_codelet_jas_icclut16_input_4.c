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
    jas_iccuint16_t *clut;
    jas_iccuint16_t numintabents;
    jas_iccuint16_t **intabs;
    jas_iccuint16_t *intabsbuf;
    jas_iccuint16_t numouttabents;
    jas_iccuint16_t **outtabs;
    jas_iccuint16_t *outtabsbuf;
} jas_icclut16_t;

int i;
jas_icclut16_t *lut16;

void init_vars() {
    lut16 = (jas_icclut16_t *)calloc(1, sizeof(jas_icclut16_t));
    if (!lut16) exit(1);

    lut16->numinchans = 4;
    lut16->numintabents = 65536;

    size_t total_intabs_size = (size_t)lut16->numinchans * lut16->numintabents;
    if (total_intabs_size > (256 * 1024 * 1024 / sizeof(jas_iccuint16_t))) {
        total_intabs_size = 256 * 1024 * 1024 / sizeof(jas_iccuint16_t);
        lut16->numinchans = 4;
        lut16->numintabents = total_intabs_size / lut16->numinchans;
    }

    lut16->intabsbuf = (jas_iccuint16_t *)calloc(total_intabs_size, sizeof(jas_iccuint16_t));
    if (!lut16->intabsbuf) exit(1);

    lut16->intabs = (jas_iccuint16_t **)calloc(lut16->numinchans, sizeof(jas_iccuint16_t *));
    if (!lut16->intabs) exit(1);

    lut16->numoutchans = 4;
    lut16->clutlen = 16;
    lut16->clut = (jas_iccuint16_t *)calloc(lut16->clutlen * lut16->clutlen * lut16->clutlen, sizeof(jas_iccuint16_t));
    if (!lut16->clut) exit(1);

    lut16->numouttabents = 65536;
    lut16->outtabsbuf = (jas_iccuint16_t *)calloc((size_t)lut16->numoutchans * lut16->numouttabents, sizeof(jas_iccuint16_t));
    if (!lut16->outtabsbuf) exit(1);

    lut16->outtabs = (jas_iccuint16_t **)calloc(lut16->numoutchans, sizeof(jas_iccuint16_t *));
    if (!lut16->outtabs) exit(1);

    for (int c = 0; c < lut16->numoutchans; ++c) {
        lut16->outtabs[c] = &lut16->outtabsbuf[c * lut16->numouttabents];
    }

    for (int r = 0; r < 3; ++r) {
        for (int s = 0; s < 3; ++s) {
            lut16->e[r][s] = (r == s) ? 1 : 0;
        }
    }

    i = 0;
}