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
    uint32_t write_offset = omega;
    for (i = 0; i < k; i++) {
        uint32_t segment_start = coeff_index;
        for (j = 0; j < 256; j++) {
            uint32_t val = p[i].coeff[j];
            // Introduce artificial WAW and WAR by reordering and temporary accumulation
            if (val != 0) {
                data[coeff_index] = j;
                coeff_index++;
            }
        }
        // Eliminate direct RAW on coeff_index for this store by using fixed base
        data[write_offset + i] = (uint8_t)(coeff_index - segment_start);
    }
}
