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

extern int y;
extern int x;
extern int exclude_cur_pos;
extern SliceContext *sc;
extern  int step;
extern int l;
extern int r;
extern int t;
extern int b;
extern int j;
extern int i;
extern int _usr_index;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Change array access to strided memory pattern by writing every 2nd element first, then filling gaps.
    // This modifies the memory access pattern of sc->search_positions to write in two passes with stride 2,
    // improving potential for vectorization or cache line utilization.

    int temp_index = 0;
    PosCode pos;

    // First pass: write to even indices (simulating strided access)
    for (j = t; j <= b; j += step) {
        for (i = l; i <= r; i += step) {
            if (exclude_cur_pos > 0 && j == y && i == x) {
                continue;
            }
            pos.y = j;
            pos.x = i;
            if (temp_index % 2 == 0 && (index + temp_index/2) < 65536) { // assuming reasonable bound
                sc->search_positions[index + temp_index/2] = pos;
            }
            temp_index++;
        }
    }

    // Second pass: write to odd indices (completing strided pattern)
    temp_index = 0;
    for (j = t; j <= b; j += step) {
        for (i = l; i <= r; i += step) {
            if (exclude_cur_pos > 0 && j == y && i == x) {
                continue;
            }
            pos.y = j;
            pos.x = i;
            if (temp_index % 2 == 1 && (index + temp_index/2 + (temp_index+1)/2) < 65536) {
                sc->search_positions[index + temp_index/2 + (temp_index+1)/2] = pos;
            }
            temp_index++;
        }
    }

    // Update index after all insertions
    index += temp_index;
}
