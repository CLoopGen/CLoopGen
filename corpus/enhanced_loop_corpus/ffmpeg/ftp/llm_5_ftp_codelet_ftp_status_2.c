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
    code_found = 0;
    for (i = 0; response_codes[i]; ++i) {
        result = (err == response_codes[i]) ? err : result;
        code_found |= (err == response_codes[i]);
    }
}
