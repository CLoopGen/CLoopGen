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
    for (i = 0; i < p->order; i++) {
        float coef = p->refl_coef[i];
        float target = p->target_refl_coef[i];
        float result = 0.59999999999999998 * coef + 0.40000000000000002 * target;
        if (coef >= 0.0f) {
            p->refl_coef[i] = result;
        } else {
            p->refl_coef[i] = coef;
        }
    }
}
