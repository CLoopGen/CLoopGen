#include <stdio.h>

#include <inttypes.h>

struct poly_st {
    uint32_t coeff[256];
};


typedef struct poly_st POLY;

extern uint32_t omega;
extern int i;
extern int j;
extern int k;
extern size_t coeff_index;
extern POLY *p;
extern uint8_t *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < k; i++, p++) {
        uint32_t local_count = coeff_index;
        for (j = 0; j < 128; j++) {
            if (p->coeff[2*j] != 0)
                data[local_count++] = 2*j;
            if (p->coeff[2*j + 1] != 0)
                data[local_count++] = 2*j + 1;
        }
        coeff_index = local_count;
        data[omega + i] = (uint8_t)coeff_index;
    }
}
