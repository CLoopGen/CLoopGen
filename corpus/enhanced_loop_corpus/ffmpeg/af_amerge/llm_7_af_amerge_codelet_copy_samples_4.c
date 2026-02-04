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
    for (i = 0; i < nb_inputs; i++) {
        nb_ch = nb_ch + in[i].nb_ch;
        in[i].nb_ch = in[i].nb_ch; // WAW dependency introduced: write after write on in[i].nb_ch (redundant but creates artificial self-dependency)
    }
}
