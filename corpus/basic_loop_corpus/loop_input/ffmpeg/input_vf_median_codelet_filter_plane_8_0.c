#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int src_linesize;
int width;
int jobnr;
uint16_t *ccoarse;
uint16_t *cfine;
int radiusV;
uint8_t *srcp;

void init_vars() {
    width = 1024;
    radiusV = 5;
    jobnr = 1;
    src_linesize = width;

    int src_size = (radiusV + (jobnr != 0) * (1 + radiusV)) * src_linesize;
    int cfine_size = (1 << ((8 + 1) / 2)) * (width * (1 << ((8 + 1) / 2))) + (1 << ((8 + 1) / 2));
    int ccoarse_size = (1 << ((8 + 1) / 2)) * width + (1 << ((8 + 1) / 2));

    srcp = (uint8_t*)calloc(src_size, sizeof(uint8_t));
    cfine = (uint16_t*)calloc(cfine_size, sizeof(uint16_t));
    ccoarse = (uint16_t*)calloc(ccoarse_size, sizeof(uint16_t));

    for (int i = 0; i < src_size; i++) {
        srcp[i] = rand() & 0xFF;
    }
}