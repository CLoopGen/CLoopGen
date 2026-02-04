#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct motion_vect {
    int d[2];
} motion_vect;

typedef struct SubcelEvaluation {
    int eval_dist[4];
    int best_bit_use;
    int best_coding;
    int subCels[4];
    motion_vect motion;
    int cbEntry;
} SubcelEvaluation;

typedef struct CelEvaluation {
    int eval_dist[4];
    int best_coding;
    SubcelEvaluation subCels[4];
    motion_vect motion;
    int cbEntry;
    int sourceX;
    int sourceY;
} CelEvaluation;

extern CelEvaluation *cel;
extern int i;
extern int divide_bit_use;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and reordering computation
    // Access subCels[0], subCels[1], subCels[2], subCels[3] in sequence with direct indexing
    cel->eval_dist[3] += cel->subCels[0].eval_dist[cel->subCels[0].best_coding];
    divide_bit_use += cel->subCels[0].best_bit_use;

    cel->eval_dist[3] += cel->subCels[1].eval_dist[cel->subCels[1].best_coding];
    divide_bit_use += cel->subCels[1].best_bit_use;

    cel->eval_dist[3] += cel->subCels[2].eval_dist[cel->subCels[2].best_coding];
    divide_bit_use += cel->subCels[2].best_bit_use;

    cel->eval_dist[3] += cel->subCels[3].eval_dist[cel->subCels[3].best_coding];
    divide_bit_use += cel->subCels[3].best_bit_use;
}
