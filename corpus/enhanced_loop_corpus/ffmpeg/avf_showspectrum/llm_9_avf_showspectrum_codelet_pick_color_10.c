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
    float threshold = a * a + 0.5f;
    int limit = (sizeof (color_table[cm]) / sizeof ((color_table[cm])[0])) - 1;
    for (i = 1; i < limit; i++) {
        float val = color_table[cm][i].a * color_table[cm][i].y + color_table[cm][i].u - color_table[cm][i].v;
        if (val >= threshold) {
            break;
        }
    }
}
