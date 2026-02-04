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
    // Variant 2: Strided memory access using pointer arithmetic with stride of 2 elements
    // Simulate strided access by stepping through indices 0 and 2, then 1 and 3 (stride 2)
    const int strides[] = {0, 2, 1, 3}; // Non-consecutive access pattern
    for (int j = 0; j < 4; j++) {
        int idx = strides[j];
        cel->eval_dist[3] += cel->subCels[idx].eval_dist[cel->subCels[idx].best_coding];
        divide_bit_use += cel->subCels[idx].best_bit_use;
    }
}
