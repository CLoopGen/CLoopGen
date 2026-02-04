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
    int batch_size = 4;
    for (len = 1; len <= max_code_length; len += 2) {
        int local_code1 = code;
        int local_code2 = code << 1;
        int end_sym = alphabet_size - (alphabet_size % batch_size);
        for (sym = 0; sym < end_sym; sym += batch_size) {
            for (int j = 0; j < batch_size; j++) {
                int idx = sym + j;
                if (idx >= alphabet_size) break;
                if (code_lengths[idx] == len) {
                    codes[idx] = local_code1++;
                    r->nb_symbols++;
                } else if (code_lengths[idx] == len + 1) {
                    codes[idx] = local_code2++;
                    r->nb_symbols++;
                }
            }
        }
        for (; sym < alphabet_size; sym++) {
            if (code_lengths[sym] == len) {
                codes[sym] = local_code1++;
                r->nb_symbols++;
            } else if (len < max_code_length && code_lengths[sym] == len + 1) {
                codes[sym] = local_code2++;
                r->nb_symbols++;
            }
        }
        code = local_code2 << 1;
    }
}
