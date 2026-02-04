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

extern int i;
extern jas_icclut8_t *lut8;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    jas_iccuint8_t i_local;
    jas_iccuint8_t numoutchans = lut8->numoutchans;
    jas_iccuint16_t numouttabents = lut8->numouttabents;
    jas_iccuint8_t *outtabsbuf = lut8->outtabsbuf;
    jas_iccuint8_t **outtabs = lut8->outtabs;

    for (i_local = 0; i_local < numoutchans; ++i_local) {
        outtabs[i_local] = &outtabsbuf[i_local * numouttabents];
    }
}
