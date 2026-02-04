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



void loop(){
    // Variant 2: Strided memory access (reverse order with stride)
    jas_iccuint16_t n = lut8->numouttabents;
    jas_iccuint8_t *base = lut8->outtabsbuf;
    for (i = 0; i < lut8->numoutchans; ++i) {
        int rev_index = lut8->numoutchans - 1 - i;  // Reverse index
        lut8->outtabs[rev_index] = &base[rev_index * n];
    }
}
