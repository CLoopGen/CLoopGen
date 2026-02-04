#include <stdio.h>

#include <inttypes.h>

extern float weakness_value[3];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            if (weakness_value[j] < weakness_value[i]) {
                float tmp = weakness_value[i];
                weakness_value[i] = weakness_value[j];
                weakness_value[j] = tmp;
            }
        }
    }
}
