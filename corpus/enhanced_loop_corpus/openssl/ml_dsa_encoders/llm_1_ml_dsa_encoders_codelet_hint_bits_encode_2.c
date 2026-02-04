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
    for (i = 0; i < k; i++) {
        j = 0;
        for (; j < 256; j++) {
            if (p->coeff[j] != 0)
                data[coeff_index++] = j;
        }
        data[omega + i] = (uint8_t)coeff_index;
        p++;
    }
}
