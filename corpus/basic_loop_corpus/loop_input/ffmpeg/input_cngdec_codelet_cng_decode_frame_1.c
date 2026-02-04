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

CNGContext *p;
int i;
float e;

static float *refl_coef_data;
static CNGContext p_instance;

void init_vars() {
    // Allocate refl_coef array with size to make loop take ~0.01 seconds
    // Assume ~1e8 iterations per second, so ~1e6 iterations for 0.01s
    const int data_size = 1 << 20; // 1M elements
    
    refl_coef_data = (float*)calloc(data_size, sizeof(float));
    if (!refl_coef_data) exit(1);
    
    // Initialize with values that won't cause underflow/overflow
    for (int j = 0; j < data_size; j++) {
        refl_coef_data[j] = (float)(j % 100) / 100.0f; // 0.0 to 0.99
    }
    
    // Initialize p->order to match allocated size
    p_instance.order = data_size;
    p_instance.refl_coef = refl_coef_data;
    
    // Initialize other required fields to avoid undefined behavior
    p_instance.target_refl_coef = NULL;
    p_instance.lpc_coef = NULL;
    p_instance.energy = 0;
    p_instance.target_energy = 0;
    p_instance.inited = 0;
    p_instance.filter_out = NULL;
    p_instance.excitation = NULL;
    p_instance.lfg.index = 0;
    for (int j = 0; j < 64; j++) {
        p_instance.lfg.state[j] = 0;
    }
    
    // Point global p to initialized instance
    p = &p_instance;
    
    // Initialize loop counter and accumulator
    i = 0;
    e = 1.0f;
}