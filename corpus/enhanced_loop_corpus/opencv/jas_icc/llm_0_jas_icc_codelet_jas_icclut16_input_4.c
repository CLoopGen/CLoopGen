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

extern int i;
extern jas_icclut16_t *lut16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; ++j)
        for (i = 0; i < lut16->numinchans; ++i)
            lut16->intabs[i] = &lut16->intabsbuf[i * lut16->numintabents];
}
