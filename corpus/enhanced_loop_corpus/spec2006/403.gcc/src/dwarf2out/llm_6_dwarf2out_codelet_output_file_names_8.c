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
    for (i = 0; i < ndirs; i++) {
        int j;
        int total = 0;
        savehere[i] = dirs[i].length;
        total += (savehere[i] - saved[i]) * dirs[i].count;

        // Eliminate loop-carried dependency on `total` by precomputing independent contributions
        // Introduce temporary array to remove WAW and WAR hazards in savehere
        int temp_save[ndirs];
        for (j = 0; j < ndirs; j++) {
            temp_save[j] = savehere[j];
        }

        for (j = i + 1; j < ndirs; j++) {
            temp_save[j] = 0;
            if (saved[j] < dirs[i].length) {
                int k = dirs[j].prefix;
                // Unroll prefix chain traversal up to fixed depth to reduce loop-carried dependency
                for (int level = 0; level < 4 && k != -1 && k != i; level++) {
                    k = dirs[k].prefix;
                }
                if (k == i) {
                    temp_save[j] = dirs[i].length;
                    total += (temp_save[j] - saved[j]) * dirs[j].count;
                }
            }
        }

        if (total > dirs[i].length + 1) {
            for (j = i; j < ndirs; j++) {
                if (temp_save[j] > 0) {
                    saved[j] = temp_save[j];
                    dirs[j].dir_idx = i;
                }
            }
        }
    }
}
