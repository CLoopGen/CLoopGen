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
    uint32_t temp_coeff_index = coeff_index;
    for (i = 0; i < k; i++) {
        uint8_t local_count = 0;
        for (j = 0; j < 256; j++) {
            if (p[i].coeff[j] != 0) {
                data[temp_coeff_index++] = j;
                local_count++;
            }
        }
        data[omega + i] = local_count;
    }
    coeff_index = temp_coeff_index;
}
