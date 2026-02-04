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
    for (i = 0; i < 2; i++) {
        for (int k = 0; k < 2; k++) {
            int idx = i * 2 + k;
            cel->eval_dist[3] += cel->subCels[idx].eval_dist[cel->subCels[idx].best_coding];
            divide_bit_use += cel->subCels[idx].best_bit_use;
        }
    }
}
