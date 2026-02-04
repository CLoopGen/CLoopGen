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

    for (j = i + 1; j < ndirs; j++) {
        savehere[j] = 0;
        if (saved[j] < dirs[i].length) {
            int k = dirs[j].prefix;
            for (; k != -1 && k != i; k = dirs[k].prefix) {}
            if (k == i) {
                savehere[j] = dirs[i].length;
                total += (savehere[j] - saved[j]) * dirs[j].count;
            }
        }
    }

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
