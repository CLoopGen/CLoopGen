#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern float values[400];
extern int m;
extern int n;
extern float contribution;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_contribution = contribution;
    for (i = -1; i <= 1; i++) {
        float local_value_update[3];
        for (j = -1; j <= 1; j++) {
            int index = (19 + 2) + (m + i) * (19 + 1) + (n + j);
            if (board[index] == 0) {
                local_value_update[j + 1] = temp_contribution;
            } else {
                local_value_update[j + 1] = 0.0f;
            }
        }
        for (j = -1; j <= 1; j++) {
            int index = (19 + 2) + (m + i) * (19 + 1) + (n + j);
            if (local_value_update[j + 1] != 0.0f) {
                values[index] += local_value_update[j + 1];
            }
        }
    }
}
