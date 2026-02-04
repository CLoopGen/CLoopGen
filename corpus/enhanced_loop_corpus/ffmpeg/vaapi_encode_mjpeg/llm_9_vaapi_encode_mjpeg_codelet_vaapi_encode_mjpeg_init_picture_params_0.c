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

extern JPEGRawFrameHeader *fh;
extern  AVPixFmtDescriptor *desc;
extern  uint8_t *components;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = (fh->Nf > 2) ? 2 : 1;
    for (i = 0; i < fh->Nf; i += step) {
        int next_i = i + 1;
        fh->C[i] = components[i];
        fh->H[i] = 1 + (i == 0 ? desc->log2_chroma_w : 0);
        fh->V[i] = 1 + (i == 0 ? desc->log2_chroma_h : 0);
        fh->Tq[i] = !!i;
        if (next_i < fh->Nf) {
            fh->C[next_i] = components[next_i];
            fh->H[next_i] = 1 + (next_i == 0 ? desc->log2_chroma_w : 0);
            fh->V[next_i] = 1 + (next_i == 0 ? desc->log2_chroma_h : 0);
            fh->Tq[next_i] = !!next_i;
        }
    }
}
