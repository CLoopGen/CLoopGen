#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVLFG {
    unsigned int state[64];
    int index;
} AVLFG;

typedef struct CNGContext {
    float *refl_coef;
    float *target_refl_coef;
    float *lpc_coef;
    int order;
    int energy;
    int target_energy;
    int inited;
    float *filter_out;
    float *excitation;
    AVLFG lfg;
} CNGContext;

static float *refl_coef_data;
static float *target_refl_coef_data;
CNGContext *p;
int i;

void init_vars() {
    // Allocate memory for arrays - aim for ~100MB total to ensure loop takes ~0.01s
    const size_t num_elements = 12500000; // 12.5M elements * 2 arrays * 4 bytes = 100MB
    
    refl_coef_data = (float*)calloc(num_elements, sizeof(float));
    target_refl_coef_data = (float*)calloc(num_elements, sizeof(float));
    
    if (!refl_coef_data || !target_refl_coef_data) {
        exit(1);
    }
    
    // Initialize data with non-zero values to make computation meaningful
    for (size_t j = 0; j < num_elements; j++) {
        refl_coef_data[j] = (float)(j % 100) / 100.0f;
        target_refl_coef_data[j] = (float)((j + 10) % 100) / 100.0f;
    }
    
    // Allocate and initialize CNGContext
    p = (CNGContext*)malloc(sizeof(CNGContext));
    if (!p) {
        exit(1);
    }
    
    p->refl_coef = refl_coef_data;
    p->target_refl_coef = target_refl_coef_data;
    p->lpc_coef = NULL;
    p->order = num_elements;  // Set order to match allocated size
    p->energy = 0;
    p->target_energy = 0;
    p->inited = 1;
    p->filter_out = NULL;
    p->excitation = NULL;
    
    // Initialize lfg
    for (int j = 0; j < 64; j++) {
        p->lfg.state[j] = j * 12345;
    }
    p->lfg.index = 0;
}