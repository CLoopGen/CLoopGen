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
for (i = 0; response_codes[i]; ++i) {
    if (err == response_codes[i]) {
        code_found = 1;
        result = err;
        break;
    }
}

}
