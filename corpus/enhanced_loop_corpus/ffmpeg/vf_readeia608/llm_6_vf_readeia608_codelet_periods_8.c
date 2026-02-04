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
    int temp_cnt = cnt;
    int temp_last = last;
    int temp_hold = hold;
    for (int i = 26; i < len + 25; i++) {
        if (line[i].output != temp_hold) {
            code[temp_cnt].size = i - temp_last;
            code[temp_cnt].bit = temp_hold;
            temp_hold = line[i].output;
            temp_last = i;
            temp_cnt++;
        }
    }
    cnt = temp_cnt;
    last = temp_last;
    hold = temp_hold;
}
