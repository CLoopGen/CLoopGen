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
    // Variant 1: Increased computational intensity by unrolling the inner loop and adding redundant arithmetic operations.
    // Trip count remains the same, but each iteration performs more work via expanded calculations and multiple position updates per cycle.
    int stride = step * 2;
    for (j = t; j <= b; j += step) {
        i = l;
        // Unroll by 2: process two iterations at once to increase arithmetic density
        for (; i <= r - step; i += stride) {
            PosCode pos1, pos2;
            // Add dummy arithmetic to increase computational load
            int calc1 = (i + step) * (i + step) + j * j;
            int calc2 = (i + stride) * (i + stride) + j * j;
            (void)calc1; (void)calc2;

            if (exclude_cur_pos > 0) {
                if (!(j == y && i == x)) {
                    pos1.y = j;
                    pos1.x = i;
                    sc->search_positions[index++] = pos1;
                }
                if (!(j == y && (i + step) == x)) {
                    pos2.y = j;
                    pos2.x = i + step;
                    sc->search_positions[index++] = pos2;
                }
            } else {
                pos1.y = j;
                pos1.x = i;
                pos2.y = j;
                pos2.x = i + step;
                sc->search_positions[index++] = pos1;
                sc->search_positions[index++] = pos2;
            }
        }
        // Handle remainder
        for (; i <= r; i += step) {
            PosCode pos;
            if (exclude_cur_pos > 0 && j == y && i == x) {
                continue;
            }
            pos.y = j;
            pos.x = i;
            sc->search_positions[index++] = pos;
        }
    }
}
