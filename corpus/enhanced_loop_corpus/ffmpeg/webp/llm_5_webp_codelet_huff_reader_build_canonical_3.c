#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size;
    int table_allocated;
} VLC;

typedef struct HuffReader {
    VLC vlc;
    int simple;
    int nb_symbols;
    uint16_t simple_symbols[2];
} HuffReader;

extern HuffReader *r;
extern int *code_lengths;
extern int alphabet_size;
extern int len;
extern int sym;
extern int code;
extern int max_code_length;
extern uint16_t *codes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (len = 1; len <= max_code_length; len++) {
        int shift_contrib = 0;
        for (sym = 0; sym < alphabet_size; sym++) {
            int matches = (code_lengths[sym] == len);
            codes[sym] += matches * code; // Only adds 'code' if match
            code += matches;              // Increment only when matched
            r->nb_symbols += matches;     // Count symbol if matched
            shift_contrib += matches;     // Track how many matched for shift logic
        }
        code <<= (shift_contrib > 0); // Equivalent to left shift by 1 if any symbol matched
    }
}
