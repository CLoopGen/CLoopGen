#include <stdio.h>

#include <inttypes.h>

extern int pieces[62];
extern int find_slot;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (find_slot = 1; find_slot < 31 && (pieces[find_slot] != 0 || pieces[find_slot + 1] != 0); find_slot += 2) {
        pieces[find_slot] ^= find_slot ^ pieces[find_slot];
    }
}
