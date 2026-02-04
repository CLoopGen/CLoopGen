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
    // Variant 2: Reverse consecutive memory access (backward traversal)
    nb_ch = 0;
    int i;
    for (i = nb_inputs - 1; i >= 0; i--) {
        nb_ch += in[i].nb_ch;
    }
}
