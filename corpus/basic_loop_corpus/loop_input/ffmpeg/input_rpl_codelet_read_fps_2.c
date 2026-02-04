#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *line;
int64_t num;
int64_t den;

static char data[16777216]; // 16MB buffer to ensure ~0.01 sec runtime

void init_vars() {
    // Initialize numeric accumulators
    num = 0;
    den = 1;
    
    // Fill data with digits to ensure long loop execution
    for (size_t i = 0; i < sizeof(data) - 1; i++) {
        data[i] = '1'; // Use '1' to avoid overflow in num/den calculations
    }
    data[sizeof(data) - 1] = '\0'; // Null terminate
    
    // Point line to beginning of data
    line = data;
}