#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct JPEGRawFrameHeader {
    uint16_t Lf;
    uint8_t P;
    uint16_t Y;
    uint16_t X;
    uint16_t Nf;
    uint8_t C[255];
    uint8_t H[255];
    uint8_t V[255];
    uint8_t Tq[255];
} JPEGRawFrameHeader;

typedef struct AVComponentDescriptor {
    int plane;
    int step;
    int offset;
    int shift;
    int depth;
    int step_minus1 __attribute__((deprecated("")));
    int depth_minus1 __attribute__((deprecated("")));
    int offset_plus1 __attribute__((deprecated("")));
} AVComponentDescriptor;

typedef struct AVPixFmtDescriptor {
    const char *name;
    uint8_t nb_components;
    uint8_t log2_chroma_w;
    uint8_t log2_chroma_h;
    uint64_t flags;
    AVComponentDescriptor comp[4];
    const char *alias;
} AVPixFmtDescriptor;

JPEGRawFrameHeader *fh;
AVPixFmtDescriptor *desc;
uint8_t *components;
int i;

void init_vars() {
    fh = (JPEGRawFrameHeader*)calloc(1, sizeof(JPEGRawFrameHeader));
    desc = (AVPixFmtDescriptor*)calloc(1, sizeof(AVPixFmtDescriptor));
    components = (uint8_t*)malloc(255 * sizeof(uint8_t));

    fh->Nf = 3;
    desc->log2_chroma_w = 1;
    desc->log2_chroma_h = 1;

    for (int j = 0; j < 255; j++) {
        components[j] = (uint8_t)(j % 256);
    }
}