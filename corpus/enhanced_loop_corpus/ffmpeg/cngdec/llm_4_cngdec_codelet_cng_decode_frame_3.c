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

extern CNGContext *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (p->order <= 0) return;
    for (i = 0; i < p->order; i++) {
        float temp = p->target_refl_coef[i];
        if (temp > 0.0f) {
            p->refl_coef[i] = 0.59999999999999998f * p->refl_coef[i] + 0.40000000000000002f * temp;
        }
    }
}
