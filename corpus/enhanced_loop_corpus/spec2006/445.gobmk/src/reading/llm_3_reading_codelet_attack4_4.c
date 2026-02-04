#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern int k;
extern struct reading_moves moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping (reverse order traversal)
    int i;
    for (i = 0; i < moves.num; i++) {
        int idx = moves.num - 1 - i;  // reverse access: last to first
        moves.score[idx] += 5;
    }
}
