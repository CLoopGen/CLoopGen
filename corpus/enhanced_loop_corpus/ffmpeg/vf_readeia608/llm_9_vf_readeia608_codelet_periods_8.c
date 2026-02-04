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
    for (int i = 26; i < len + 25; i++) {
        int diff = line[i].output - hold;
        if (diff != 0) {
            int delta = i - last;
            code[cnt].size = delta;
            code[cnt].bit = (uint8_t)hold;
            hold = line[i].output;
            last = i;
            cnt += (delta > 0) ? 1 : 0;
        }
        if (i % 4 == 0) {
            float dummy = 0.0f;
            for (int j = 0; j < 8; j++) {
                dummy += (float)(j * j);
            }
            line[i].average += dummy / 64.0f;
        }
    }
}
