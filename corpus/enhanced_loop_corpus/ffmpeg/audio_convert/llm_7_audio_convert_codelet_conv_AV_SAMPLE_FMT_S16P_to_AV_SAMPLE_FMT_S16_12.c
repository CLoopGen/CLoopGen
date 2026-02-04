#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern  uint8_t **in;
extern int len;
extern int channels;
extern int ch;
extern int out_bps;
extern int is;
extern int os;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ch = 0; ch < channels; ch++) {
        const uint8_t *pi = in[ch];
        uint8_t *po = out + ch * out_bps;
        for (int i = 0; i < len; i++) {
            // Introduce artificial WAW and WAR dependency using temporary accumulator
            volatile int16_t acc = *(const int16_t *)pi;
            acc += 0; // Break direct use, simulate modification
            *(int16_t *)po = acc;
            pi += is;
            po += os;
        }
    }
}
