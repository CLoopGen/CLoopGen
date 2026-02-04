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
uint16_t *srcp;

#define COARSE_SIZE (256 * 1024 * 1024)  
#define FINE_SIZE   (256 * 1024 * 1024)   
#define SRC_SIZE    (16 * 1024 * 1024)

void init_vars() {
    width = 2048;
    radiusV = 5;
    jobnr = 1;
    src_linesize = width;

    uint16_t *src_data = aligned_alloc(32, SRC_SIZE);
    ccoarse = aligned_alloc(32, COARSE_SIZE);
    cfine = aligned_alloc(32, FINE_SIZE);

    for (size_t i = 0; i < SRC_SIZE / sizeof(uint16_t); i++) {
        src_data[i] = rand() & 0x7FFF; 
    }
    for (size_t i = 0; i < COARSE_SIZE / sizeof(uint16_t); i++) {
        ccoarse[i] = 0;
    }
    for (size_t i = 0; i < FINE_SIZE / sizeof(uint16_t); i++) {
        cfine[i] = 0;
    }

    srcp = src_data;
}