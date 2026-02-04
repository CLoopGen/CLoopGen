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
    int *local_codes = (int*)alloca(alphabet_size * sizeof(int));
    int local_nb_symbols = 0;
    int current_code = 0;

    for (len = 1; len <= max_code_length; len++) {
        int next_code = current_code;
        for (sym = 0; sym < alphabet_size; sym++) {
            if (code_lengths[sym] != len)
                continue;
            local_codes[sym] = next_code++;
            local_nb_symbols++;
        }
        current_code = next_code << 1;
    }

    // Write back to global state
    for (sym = 0; sym < alphabet_size; sym++) {
        if (code_lengths[sym] > 0) {
            codes[sym] = local_codes[sym];
        }
    }
    r->nb_symbols = local_nb_symbols;
    code = current_code;
}
