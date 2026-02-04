#include <stdio.h>

#include <inttypes.h>

extern int pieces[62];
extern int find_slot;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (find_slot = 1; (pieces[find_slot] != 0); find_slot++)
    ((void)(0));

}
