#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct hnode {
    int count;
    unsigned char used;
    int children[2];
} hnode;

hnode *hnodes;
int i;

void init_vars() {
    hnodes = (hnode *)calloc(256 * 2, sizeof(hnode));
}

void loop(); 

void call_loop() {
    init_vars();
    loop();
}