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
if (length <= 0) return;
int block_size = 4;
int remainder = length % block_size;
int limit = length - remainder;

for (int i = 0; i < limit; i += block_size) {
    out[i]     = (in[i]     * win[i]    ) >> shift;
    out[i + 1] = (in[i + 1] * win[i + 1]) >> shift;
    out[i + 2] = (in[i + 2] * win[i + 2]) >> shift;
    out[i + 3] = (in[i + 3] * win[i + 3]) >> shift;
}

for (int i = limit; i < length; i++) {
    out[i] = (in[i] * win[i]) >> shift;
}
}
