#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct amerge_input {
    int nb_ch;
};


extern int nb_inputs;
extern struct amerge_input in[];
extern int i;
extern int nb_ch;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2, with bounds check)
    nb_ch = 0;
    int stride = 2;
    int i;
    for (i = 0; i < nb_inputs; i += stride) {
        nb_ch += in[i].nb_ch;
        // Handle remaining element if stride skips the last one
        if (i + 1 < nb_inputs) {
            nb_ch += in[i + 1].nb_ch;
        }
    }
}
