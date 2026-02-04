#include <stdio.h>

#include <inttypes.h>

struct string_data {
    int color;
    int size;
    int origin;
    int liberties;
    int libs[20];
    int neighbors;
    int neighborlist[160];
    int mark;
};


struct change_stack_entry {
    int *address;
    int value;
};


extern struct string_data string[240];
extern struct change_stack_entry *change_stack_pointer;
extern int s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (k = 0; k < string[s].liberties && k < 20; k += 2) {
        struct change_stack_entry *tmp = change_stack_pointer++;
        tmp->address = &(string[s].libs[k]);
        tmp->value = string[s].libs[k];
        if (k + 1 < string[s].liberties && k + 1 < 20) {
            struct change_stack_entry *tmp2 = change_stack_pointer++;
            tmp2->address = &(string[s].libs[k + 1]);
            tmp2->value = string[s].libs[k + 1];
        }
    }
}
