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
    // Variant 2: Reduced trip count by half with stride-2 loop, but maintains coverage via dual pointer assignment per iteration
    // Simulates reduced loop iterations with preserved workload distribution
    jas_iccuint8_t limit = (lut8->numoutchans + 1) / 2;
    for (i = 0; i < limit; ++i) {
        jas_iccuint16_t base_index1 = i * 2 * lut8->numouttabents;
        jas_iccuint16_t base_index2 = (i * 2 + 1) * lut8->numouttabents;
        lut8->outtabs[i * 2] = &lut8->outtabsbuf[base_index1];
        if ((i * 2 + 1) < lut8->numoutchans) {
            lut8->outtabs[i * 2 + 1] = &lut8->outtabsbuf[base_index2];
        }
    }
}
