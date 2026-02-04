#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern int reload_n_operands;
extern HARD_REG_ELT_TYPE reload_reg_used_in_input_addr[30];
extern HARD_REG_ELT_TYPE reload_reg_used_in_inpaddr_addr[30];
extern HARD_REG_ELT_TYPE reload_reg_used_in_output_addr[30];
extern HARD_REG_ELT_TYPE reload_reg_used_in_outaddr_addr[30];
extern HARD_REG_ELT_TYPE reload_reg_used_in_input[30];
extern HARD_REG_ELT_TYPE reload_reg_used_in_output[30];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    HARD_REG_ELT_TYPE temp_input[30];
    HARD_REG_ELT_TYPE temp_output[30];
    for (i = 0; i < reload_n_operands; i++) {
        temp_output[i] = reload_reg_used_in_output[i];
        temp_input[i] = reload_reg_used_in_input[i];
        ((reload_reg_used_in_output[i]) = ((HARD_REG_ELT_TYPE)(0)));
        ((reload_reg_used_in_input[i]) = ((HARD_REG_ELT_TYPE)(0)));
        ((reload_reg_used_in_input_addr[i]) = ((HARD_REG_ELT_TYPE)(0)));
        ((reload_reg_used_in_inpaddr_addr[i]) = ((HARD_REG_ELT_TYPE)(0)));
        ((reload_reg_used_in_output_addr[i]) = ((HARD_REG_ELT_TYPE)(0)));
        ((reload_reg_used_in_outaddr_addr[i]) = ((HARD_REG_ELT_TYPE)(0)));
        if (i > 0) {
            reload_reg_used_in_output[i] |= temp_output[i-1];
            reload_reg_used_in_input[i] |= temp_input[i-1];
        }
    }
}
