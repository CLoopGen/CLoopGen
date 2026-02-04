#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *in;
extern  int16_t *win;
extern int length;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < length; i++) {
        int sum = 0;
        for (int j = 0; j < 1; j++) {
            sum += in[i] * win[-i];
        }
        out[i] = sum >> shift;
    }
}
