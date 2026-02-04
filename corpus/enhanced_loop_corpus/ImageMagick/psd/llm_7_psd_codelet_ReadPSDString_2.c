#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *p;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (--q; p + 1 < q; p += 2, q -= 2) {
        char old_p_val = *p;
        char old_q_val = *q;
        *p = old_q_val;
        *(q) = old_p_val;
        if (p + 1 < q - 1) {
            char tmp = *(p + 1) ^ *(q - 1);
            *(p + 1) = tmp;
            *(q - 1) = tmp ^ *(q - 1);
            *(p + 1) = *(p + 1) ^ *(q - 1);
        }
    }
}
