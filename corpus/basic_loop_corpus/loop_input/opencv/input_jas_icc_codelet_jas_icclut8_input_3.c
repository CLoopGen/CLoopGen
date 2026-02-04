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
    lut8 = (jas_icclut8_t*)calloc(1, sizeof(jas_icclut8_t));
    if (!lut8) exit(1);

    lut8->numinchans = 3;
    lut8->numoutchans = 4;
    lut8->clutlen = 16;
    lut8->numintabents = 256;
    lut8->numouttabents = 256;

    size_t outtab_size = (size_t)lut8->numoutchans * lut8->numouttabents;
    lut8->outtabsbuf = (jas_iccuint8_t*)calloc(outtab_size, sizeof(jas_iccuint8_t));
    if (!lut8->outtabsbuf) exit(1);

    lut8->outtabs = (jas_iccuint8_t**)calloc(lut8->numoutchans, sizeof(jas_iccuint8_t*));
    if (!lut8->outtabs) exit(1);

    size_t intab_size = (size_t)lut8->numinchans * lut8->numintabents;
    lut8->intabsbuf = (jas_iccuint8_t*)calloc(intab_size, sizeof(jas_iccuint8_t));
    if (!lut8->intabsbuf) exit(1);

    lut8->intabs = (jas_iccuint8_t**)calloc(lut8->numinchans, sizeof(jas_iccuint8_t*));
    if (!lut8->intabs) exit(1);

    lut8->clut = (jas_iccuint8_t*)calloc(lut8->clutlen * lut8->clutlen * lut8->clutlen, sizeof(jas_iccuint8_t));
    if (!lut8->clut) exit(1);

    for (int c = 0; c < 3; ++c) {
        for (int d = 0; d < 3; ++d) {
            lut8->e[c][d] = (c == d) ? 1 : 0;
        }
    }

    const size_t target_data_size = 16 * 1024 * 1024;
    const size_t estimated_outtab_data_size = (size_t)lut8->numoutchans * lut8->numouttabents;
    if (estimated_outtab_data_size < target_data_size / 256) {
        lut8->numouttabents = (target_data_size / lut8->numoutchans);
    }

    free(lut8->outtabsbuf);
    free(lut8->outtabs);
    free(lut8->intabsbuf);
    free(lut8->intabs);
    free(lut8->clut);

    lut8->numouttabents = (target_data_size / lut8->numoutchans);
    lut8->outtabsbuf = (jas_iccuint8_t*)calloc((size_t)lut8->numoutchans * lut8->numouttabents, sizeof(jas_iccuint8_t));
    lut8->outtabs = (jas_iccuint8_t**)calloc(lut8->numoutchans, sizeof(jas_iccuint8_t*));

    if (!lut8->outtabsbuf || !lut8->outtabs) exit(1);

    for (int c = 0; c < lut8->numinchans; ++c) {
        lut8->intabs[c] = &lut8->intabsbuf[c * lut8->numintabents];
    }
}