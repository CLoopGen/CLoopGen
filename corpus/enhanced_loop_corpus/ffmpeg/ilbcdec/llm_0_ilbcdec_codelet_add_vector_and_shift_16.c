#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *in1;
extern  int16_t *in2;
extern int length;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < length; i++) {
        int sum = in1[i] + in2[i];
        for (int j = 0; j < 1; j++) { // Artificially increased loop nesting depth
            out[i] = sum >> shift;
        }
    }
}
