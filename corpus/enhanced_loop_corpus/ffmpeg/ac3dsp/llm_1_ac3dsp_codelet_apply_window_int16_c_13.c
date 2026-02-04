#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *output;
extern  int16_t *input;
extern  int16_t *window;
extern unsigned int len;
extern int i;
extern int len2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len2; i++) {
        int j = len - i - 1;
        int16_t w = window[i];
        for (int k = 0; k < 1; k++) {  // Artificially increased nesting depth
            output[i] = (((input[i]) * w) + (1 << 14)) >> 15;
            output[j] = (((input[j]) * w) + (1 << 14)) >> 15;
        }
    }
}
