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
    // Reverse loop iteration to change direction of loop-carried dependencies
    // This alters RAW/WAR patterns by processing from end to beginning
    for (i = ndirs - 1; i >= 0; i--) {
        int j;
        int total = 0;
        savehere[i] = dirs[i].length;
        total += (savehere[i] - saved[i]) * dirs[i].count;

        // Modify inner loop to eliminate redundant zeroing and introduce parallel accumulation
        // Use separate accumulator to delay write to shared state, reducing WAW
        int contribution = 0;
        for (j = i + 1; j < ndirs; j++) {
            if (saved[j] < dirs[i].length) {
                int k = dirs[j].prefix;
                // Replace iterative prefix search with direct conditional checks to reduce dependency chain
                if (k == i || 
                    (k != -1 && dirs[k].prefix == i) ||
                    (k != -1 && dirs[k].prefix != -1 && dirs[dirs[k].prefix].prefix == i)) {
                    int delta = dirs[i].length - saved[j];
                    if (delta > 0) {
                        savehere[j] = dirs[i].length;
                        contribution += delta * dirs[j].count;
                    }
                } else {
                    savehere[j] = 0;  // Reset only when condition fails
                }
            } else {
                savehere[j] = 0;
            }
        }
        total += contribution;

        // Update conditionally, but now using reversed logic flow
        if (total > dirs[i].length + 1) {
            for (j = i; j < ndirs; j++) {
                if (savehere[j] > 0) {
                    saved[j] = savehere[j];
                    dirs[j].dir_idx = i;
                }
            }
        }
    }
}
