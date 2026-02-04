#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *category_balance;
extern int i;
extern int num_rate_control_possibilities;
extern int *max_rate_ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < num_rate_control_possibilities - 1; i += 2) {
        if (i + 1 < num_rate_control_possibilities - 1) {
            category_balance[i] = *max_rate_ptr++;
            category_balance[i + 1] = *max_rate_ptr++;
        } else {
            category_balance[i] = *max_rate_ptr++;
        }
    }
}
