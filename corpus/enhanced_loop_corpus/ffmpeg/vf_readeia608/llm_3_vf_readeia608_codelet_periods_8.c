#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct LineItem {
    int input;
    int output;
    float unfiltered;
    float filtered;
    float average;
    float deviation;
} LineItem;

typedef struct CodeItem {
    uint8_t bit;
    int size;
} CodeItem;

extern  LineItem *line;
extern CodeItem *code;
extern int len;
extern int hold;
extern int cnt;
extern int last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array (simulated with arithmetic offset array)
    // Using precomputed indirect indices: access pattern becomes non-linear
    int stride = 4;
    int indices[4] = {0, 1, -1, 2}; // offset pattern applied around base index

    for (int i = 25 + 1; i < len + 25; i++) {
        for (int j = 0; j < 4; j++) {
            int idx = i + indices[j];
            // Bounds check
            if (idx >= 25 + 1 && idx < len + 25) {
                if (line[idx].output != hold) {
                    code[cnt].size = idx - last;
                    code[cnt].bit = hold;
                    hold = line[idx].output;
                    last = idx;
                    cnt++;
                }
            }
        }
    }
}
