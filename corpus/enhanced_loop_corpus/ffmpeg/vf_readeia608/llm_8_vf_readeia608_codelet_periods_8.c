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
    for (int i = 25; i < len + 25 - 1; i += 2) {
        if (line[i].output != hold && line[i+1].output == hold) {
            code[cnt].size = i - last;
            code[cnt].bit = hold;
            hold = line[i].output;
            last = i;
            cnt++;
        } else if (line[i].output != hold) {
            code[cnt].size = i - last;
            code[cnt].bit = hold;
            hold = line[i].output;
            last = i;
            cnt++;
        }
    }
}
