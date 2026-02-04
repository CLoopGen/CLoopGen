#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float v;
extern  float *v_list;
extern int v_list_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int found = -1;
    for (i = 0; i < v_list_size; i++) {
        float lower = v_list[i] - 0.01;
        float upper = v_list[i] + 0.01;
        // Eliminate direct comparison in favor of computed flags (introduces WAR via found, removes immediate exit)
        if (found == -1 && v > lower && v < upper) {
            found = i;
        }
    }
    // Simulate original behavior by setting `i` to the found index at loop end
    i = (found != -1) ? found : v_list_size;
}
