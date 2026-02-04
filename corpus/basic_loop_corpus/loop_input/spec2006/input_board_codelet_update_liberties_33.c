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

struct string_data string[240];
struct change_stack_entry change_stack[1000000];
struct change_stack_entry *change_stack_pointer;

int s = 120;
int k;

void init_vars() {
    for (int i = 0; i < 240; i++) {
        string[i].color = i * 3;
        string[i].size = i % 15 + 1;
        string[i].origin = i * 7;
        string[i].liberties = (i % 21); // Ensure less than or equal to 20
        string[i].neighbors = (i % 161);
        string[i].mark = i % 2;
        
        for (int j = 0; j < 20; j++) {
            string[i].libs[j] = i * 100 + j;
        }
        
        for (int j = 0; j < 160; j++) {
            string[i].neighborlist[j] = (i + j) % 240;
        }
    }

    change_stack_pointer = change_stack;
}