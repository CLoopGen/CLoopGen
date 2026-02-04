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
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < 4; i++) {
            cel->eval_dist[3] += cel->subCels[i].eval_dist[cel->subCels[i].best_coding];
            divide_bit_use += cel->subCels[i].best_bit_use;
        }
    }
}
