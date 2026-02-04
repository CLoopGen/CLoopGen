#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE test_index_array[5];
extern INT_TYPE test_rank_array[5];
extern INT_TYPE S_test_index_array[5];
extern INT_TYPE S_test_rank_array[5];
extern INT_TYPE W_test_index_array[5];
extern INT_TYPE W_test_rank_array[5];
extern INT_TYPE A_test_index_array[5];
extern INT_TYPE A_test_rank_array[5];
extern INT_TYPE B_test_index_array[5];
extern INT_TYPE B_test_rank_array[5];
extern INT_TYPE C_test_index_array[5];
extern INT_TYPE C_test_rank_array[5];
extern int i;



void loop(){
    INT_TYPE temp_index[5];
    INT_TYPE temp_rank[5];
    for (i = 0; i < 5; i++) {
        temp_index[i] = A_test_index_array[i];
        temp_rank[i] = A_test_rank_array[i];
    }
    for (i = 0; i < 5; i++) {
        test_index_array[i] = temp_index[i];
        test_rank_array[i] = temp_rank[i];
    }
}
