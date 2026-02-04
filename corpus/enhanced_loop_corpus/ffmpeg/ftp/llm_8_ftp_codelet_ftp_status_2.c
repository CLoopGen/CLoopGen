#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int response_codes[];
extern int err;
extern int i;
extern int result;
extern int code_found;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled checks
    code_found = 0;
    result = 0;
    for (i = 0; response_codes[i] && i < 128; i += 4) {  // Increased trip count bound and step size
        int val0 = response_codes[i + 0];
        int val1 = response_codes[i + 1];
        int val2 = response_codes[i + 2];
        int val3 = response_codes[i + 3];

        if (val0 == err && val0 != 0) {
            code_found = 1;
            result = val0;
            break;
        }
        if (val1 == err && val1 != 0) {
            code_found = 1;
            result = val1;
            break;
        }
        if (val2 == err && val2 != 0) {
            code_found = 1;
            result = val2;
            break;
        }
        if (val3 == err && val3 != 0) {
            code_found = 1;
            result = val3;
            break;
        }
    }
}
