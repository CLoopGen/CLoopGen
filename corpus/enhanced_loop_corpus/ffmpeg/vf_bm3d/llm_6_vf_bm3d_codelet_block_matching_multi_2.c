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
    int temp_index = index; // Introduce temporary variable to eliminate WAW hazard on shared 'index'
    for (j = t; j <= b; j += step) {
        for (i = l; i <= r; i += step) {
            PosCode pos;
            if (exclude_cur_pos > 0 && j == y && i == x) {
                continue;
            }
            pos.y = j;
            pos.x = i;
            sc->search_positions[temp_index] = pos;
            temp_index++; // Update local copy, removing loop-carried WAW dependency on global 'index'
        }
    }
    index = temp_index; // Commit final value after loop
}
