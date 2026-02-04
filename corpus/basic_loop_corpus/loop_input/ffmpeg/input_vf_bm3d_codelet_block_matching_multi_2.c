#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DCTContext DCTContext;

typedef float FFTSample;

typedef struct PosPairCode {
    double score;
    int x;
    int y;
} PosPairCode;

typedef struct PosCode {
    int x;
    int y;
} PosCode;

typedef struct SliceContext {
    DCTContext *gdctf;
    DCTContext *gdcti;
    DCTContext *dctf;
    DCTContext *dcti;
    FFTSample *bufferh;
    FFTSample *bufferv;
    FFTSample *bufferz;
    FFTSample *buffer;
    FFTSample *rbufferh;
    FFTSample *rbufferv;
    FFTSample *rbufferz;
    FFTSample *rbuffer;
    float *num;
    float *den;
    PosPairCode match_blocks[256];
    int nb_match_blocks;
    PosCode *search_positions;
} SliceContext;

int y = 100;
int x = 100;
int exclude_cur_pos = 1;
SliceContext *sc;
int step = 1;
int l = 0;
int r = 1023;
int t = 0;
int b = 1023;
int j;
int i;
int _usr_index;

#define index _usr_index

void init_vars() {
    sc = (SliceContext*)calloc(1, sizeof(SliceContext));
    if (!sc) exit(1);

    const size_t total_elements = ((b - t + 1 + step - 1) / step) * ((r - l + 1 + step - 1) / step);
    sc->search_positions = (PosCode*)malloc(total_elements * sizeof(PosCode));
    if (!sc->search_positions) exit(1);

    sc->nb_match_blocks = 0;

    index = 0;
}