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
    float alpha = 0.59999999999999998f;
    float beta = 0.40000000000000002f;
    float *r = p->refl_coef;
    float *t = p->target_refl_coef;
    int n = p->order;

    for (i = 0; i < n; i++) {
        float temp = r[i];
        r[i] = alpha * temp + beta * t[i];
    }
}
