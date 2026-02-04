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



void loop(){
    nb_ch = 0;
    for (i = 0; i < nb_inputs * 2; i++) {
        if (i < nb_inputs) {
            nb_ch += in[i].nb_ch;
        }
    }
}
