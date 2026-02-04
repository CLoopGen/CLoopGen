#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *item_str;
int *nb_items;
char *p;

static char data[1 << 24]; // 16 MB buffer
static int counter;

void init_vars() {
    size_t len = sizeof(data) - 1;
    size_t i;

    item_str = data;
    nb_items = &counter;
    p = NULL;

    counter = 0;

    for (i = 0; i < len; i++) {
        if ((rand() % 16) == 0)
            data[i] = '|';
        else
            data[i] = 'a' + (rand() % 26);
    }
    data[len] = '\0';
}