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
    int temp_code = 0;
    for (len = 1; len <= max_code_length; len++) {
        int local_symbol_count = 0;
        for (sym = 0; sym < alphabet_size; sym++) {
            if (code_lengths[sym] != len)
                continue;
            codes[sym] = temp_code++;
            local_symbol_count++;
        }
        r->nb_symbols += local_symbol_count;
        temp_code <<= 1;
    }
    code = temp_code;
}
