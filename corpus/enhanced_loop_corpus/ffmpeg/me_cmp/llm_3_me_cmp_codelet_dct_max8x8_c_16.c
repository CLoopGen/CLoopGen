#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*temp);
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via stride reversal)
    // Simulate indirect access by accessing elements in reverse order (a form of non-consecutive pattern)
    for (i = 63; i >= 0; i--) {
        int16_t val = temp[i];
        int abs_val = (val >= 0) ? val : -val;
        sum = (sum > abs_val) ? sum : abs_val;
    }
}
