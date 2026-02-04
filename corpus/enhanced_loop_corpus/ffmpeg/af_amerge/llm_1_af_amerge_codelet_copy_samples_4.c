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
    if (nb_inputs > 0) {
        i = 0;
        for (; i < nb_inputs; ) {
            nb_ch += in[i].nb_ch;
            i++;
        }
    }
}
