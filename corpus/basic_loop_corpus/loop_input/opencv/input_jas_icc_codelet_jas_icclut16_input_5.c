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
    lut16 = (jas_icclut16_t *)malloc(sizeof(jas_icclut16_t));
    lut16->numoutchans = 4;
    lut16->numouttabents = 16384;
    size_t outtab_size = (size_t)lut16->numoutchans * lut16->numouttabents;
    lut16->outtabsbuf = (jas_iccuint16_t *)calloc(outtab_size, sizeof(jas_iccuint16_t));
    lut16->outtabs = (jas_iccuint16_t **)malloc(lut16->numoutchans * sizeof(jas_iccuint16_t *));
}