#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

int influence[400];
int ii;
int k;
int queue[400];
int queue_end;
int working[400];

void init_vars() {
    queue_end = 400;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < 400; i++) {
        queue[i] = rand() % 400;
        influence[i] = rand() % 1000;
        working[i] = rand() % 1000;
    }
}