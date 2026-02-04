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

CelEvaluation *cel;
int i;
int divide_bit_use;

void init_vars() {
    cel = (CelEvaluation*)calloc(1, sizeof(CelEvaluation));
    
    // Initialize eval_dist to non-zero values for observable accumulation
    for (int j = 0; j < 4; j++) {
        cel->eval_dist[j] = j + 1;
    }
    
    cel->best_coding = 0;
    cel->motion.d[0] = 10;
    cel->motion.d[1] = 20;
    cel->cbEntry = 0;
    cel->sourceX = 0;
    cel->sourceY = 0;
    
    // Initialize each subCel
    for (int i = 0; i < 4; i++) {
        SubcelEvaluation* sub = &cel->subCels[i];
        
        // Set valid best_coding in range [0,3] since it indexes eval_dist[best_coding]
        sub->best_coding = i;  // Valid index 0-3
        
        // Initialize eval_dist so we don't access out of bounds
        for (int j = 0; j < 4; j++) {
            sub->eval_dist[j] = (i + 1) * (j + 1) * 100;
        }
        
        sub->best_bit_use = (i + 1) * 50;
        
        for (int j = 0; j < 4; j++) {
            sub->subCels[j] = j;
        }
        
        sub->motion.d[0] = i * 2;
        sub->motion.d[1] = i * 3;
        sub->cbEntry = i;
    }
    
    divide_bit_use = 0;
}