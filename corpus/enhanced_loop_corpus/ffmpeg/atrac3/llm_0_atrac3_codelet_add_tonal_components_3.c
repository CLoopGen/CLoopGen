#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct TonalComponent {
    int pos;
    int num_coefs;
    float coef[8];
} TonalComponent;

extern float *spectrum;
extern int num_components;
extern TonalComponent *components;
extern int i;
extern int j;
extern int last_pos;
extern float *input;
extern float *output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num_components; i++) {
        last_pos = ((components[i].pos + components[i].num_coefs) > last_pos) ? (components[i].pos + components[i].num_coefs) : last_pos;
        input = components[i].coef;
        output = &spectrum[components[i].pos];
        j = 0;
        if (j < components[i].num_coefs) {
            do {
                output[j] += input[j];
                j++;
            } while (j < components[i].num_coefs);
        }
    }
}
