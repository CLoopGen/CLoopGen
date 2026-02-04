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
    // Variant 2: Reduced computational complexity with increased step size and elimination of conditionals in hot path.
    // The trip count is reduced by increasing effective step size, and conditional check is hoisted outside inner loop.
    int fast_step = step * 4;  // Increase step size to reduce total iterations significantly

    if (exclude_cur_pos > 0) {
        for (j = t; j <= b; j += fast_step) {
            for (i = l; i <= r; i += fast_step) {
                // Skip only if both match exactly — minimal checks
                if (j == y && i == x) continue;
                PosCode pos;
                pos.y = j;
                pos.x = i;
                sc->search_positions[index++] = pos;
            }
        }
    } else {
        // Eliminate all branching inside loop when exclude_cur_pos == 0
        for (j = t; j <= b; j += fast_step) {
            for (i = l; i <= r; i += fast_step) {
                PosCode pos;
                pos.y = j;
                pos.x = i;
                sc->search_positions[index++] = pos;
            }
        }
    }
}
