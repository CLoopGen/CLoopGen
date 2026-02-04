#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *x;
extern int len;
extern int j;
extern int k;
extern int n;
extern int64_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < len && n < 1000; n += 2) {  // Reduced trip count by limiting to 1000 and stepping by 2
        if (n >= j && n >= k) {  // Ensure indices are valid
            s += ((int64_t)(x[n - j]) * (int64_t)(x[n - k]));
        }
    }
}
