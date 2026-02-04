#include <stdio.h>

#include <inttypes.h>

struct dir_info {
    char *path;
    int length;
    int prefix;
    int count;
    int dir_idx;
    int used;
};


extern struct dir_info *dirs;
extern int *saved;
extern int *savehere;
extern int ndirs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use indirect memory access via an index remapping array to alter access pattern
    int *index_map = saved; // Reuse existing allocated memory as scratch for indices
    for (i = 0; i < ndirs; i++) {
        index_map[i] = i; // Create identity map, could be randomized or reordered in real use
    }

    for (i = 0; i < ndirs; i++) {
        int j;
        int total;
        int curr = index_map[i]; // Indirect access to current directory
        savehere[curr] = dirs[curr].length;
        total = (savehere[curr] - saved[curr]) * dirs[curr].count;

        // Traverse remaining elements using indirect indexing
        for (j = i + 1; j < ndirs; j++) {
            int target = index_map[j]; // Remapped index
            savehere[target] = 0;
            if (saved[target] < dirs[curr].length) {
                int k = dirs[target].prefix;
                // Simulate while(k != -1 && k != i) using for-loop with limit
                int iter = 0;
                for (; iter < ndirs && k != -1 && k != curr; iter++) {
                    k = dirs[k].prefix;
                }
                if (k == curr) {
                    savehere[target] = dirs[curr].length;
                    total += (savehere[target] - saved[target]) * dirs[target].count;
                }
            }
        }

        if (total > dirs[curr].length + 1) {
            for (j = i; j < ndirs; j++) {
                int target = index_map[j];
                if (savehere[target] > 0) {
                    saved[target] = savehere[target];
                    dirs[target].dir_idx = curr;
                }
            }
        }
    }
}
