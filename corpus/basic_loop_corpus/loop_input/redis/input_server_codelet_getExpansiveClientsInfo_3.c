#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t ClientsPeakMemInput[8] = {100000, 200000, 150000, 300000, 250000, 400000, 350000, 450000};
size_t ClientsPeakMemOutput[8] = {90000, 190000, 140000, 290000, 240000, 390000, 340000, 440000};
size_t i = 0;
size_t o = 0;

void init_vars() {
    const uint64_t start_seed = 12345;
    uint64_t *input_ptr = (uint64_t*)ClientsPeakMemInput;
    uint64_t *output_ptr = (uint64_t*)ClientsPeakMemOutput;
    
    for (int k = 0; k < 8; k++) {
        input_ptr[k] = (start_seed * (k + 1)) % 500000;
        output_ptr[k] = (start_seed * (k + 2)) % 450000;
    }
    
    i = 50000;
    o = 45000;
}