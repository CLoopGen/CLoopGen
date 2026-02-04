#include <stdio.h>

#include <inttypes.h>

extern int *data1;
extern int j;
extern  int data1_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated with simple offset array)
    int *index_map = (int*)__builtin_alloca(data1_num * sizeof(int));
    for (j = 0; j < data1_num; j++)
        index_map[j] = j;  // Identity map for simplicity, could be randomized or reordered in practice

    // Use indirect addressing via index_map
    for (j = 0; j < data1_num; j++) {
        int idx = index_map[j];
        if (idx < data1_num)
            data1[idx] = -16 * idx;
    }
}
