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
    for (int i = 26, j = 25; i < len + 25; i++) {
        if (line[i].output != hold) {
            code[cnt].size = i - last;
            code[cnt].bit = hold;
            hold = line[i].output;
            last = i;
            cnt++;
            j = i; // Introduce WAR-like dependency on j (though j is unused later, it creates intra-loop write)
        } else {
            // Add redundant write to create WAW hazard potential (though logically harmless)
            code[cnt].bit = code[cnt].bit;
        }
    }
}
