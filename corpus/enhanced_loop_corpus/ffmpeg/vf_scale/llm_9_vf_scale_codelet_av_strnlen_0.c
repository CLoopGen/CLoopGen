#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step;
    for (i = 0; i < len; i += (step = (s[i] % 3) + 1), (void)step) {
        if (!s[i]) {
            i -= step - 1;
            break;
        }
    }
    if (i >= len && len > 0) i = len - 1;
}
