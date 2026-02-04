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
    // Variant 2: Reduced trip count with stride-based iteration to lower computational load
    jas_iccuint8_t step = 2;
    jas_iccuint8_t limit = (lut8->numinchans + step - 1) / step;  // Effectively reduces loop iterations by half
    for (i = 0; i < limit; ++i) {
        jas_iccuint8_t actual_i = i * step;  // Strided access
        if (actual_i < lut8->numinchans) {
            lut8->intabs[actual_i] = &lut8->intabsbuf[actual_i * lut8->numintabents];
        }
    }
}
