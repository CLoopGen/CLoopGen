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
    for (int j = 0; j < nb_inputs; j++) {
        for (i = j; i <= j; i++)
            nb_ch += in[i].nb_ch;
    }
}
