#include <stdint.h>

struct poly_st {
    uint32_t coeff[256];
};

typedef struct poly_st POLY;

static POLY in_data;
static POLY out_data;
POLY *in = &in_data;
POLY *out = &out_data;
int i;

void init_vars() {
    for (int j = 0; j < 256; j++) {
        in_data.coeff[j] = j * 31;
        out_data.coeff[j] = 0;
    }
}