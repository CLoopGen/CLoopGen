#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct ColorTable {
    float a;
    float y;
    float u;
    float v;
};


extern  struct ColorTable color_table[][8];
extern float a;
extern  int cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int n = (sizeof (color_table[cm]) / sizeof ((color_table[cm])[0])) - 1;
    for (i = 1; i < n; i++) {
        float val = color_table[cm][i].a;
        if (val >= a) {
            i++;
            break;
        } else {
            continue;
        }
    }
}
