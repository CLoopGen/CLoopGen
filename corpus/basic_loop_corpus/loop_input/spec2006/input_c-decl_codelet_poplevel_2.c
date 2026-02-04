#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union tree_node *tree;

enum tree_code {
    ERROR_MARK,
    IDENTIFIER_NODE,
    TREE_LIST,
    TREE_VEC,
    BLOCK,
    VOID_TYPE,
    INTEGER_TYPE,
    REAL_TYPE,
    COMPLEX_TYPE,
    VECTOR_TYPE,
    ENUMERAL_TYPE,
    BOOLEAN_TYPE,
    CHAR_TYPE,
    POINTER_TYPE,
    OFFSET_TYPE,
    REFERENCE_TYPE,
    METHOD_TYPE,
    FILE_TYPE,
    ARRAY_TYPE,
    SET_TYPE,
    RECORD_TYPE,
    UNION_TYPE,
    QUAL_UNION_TYPE,
    FUNCTION_TYPE,
    LANG_TYPE,
    INTEGER_CST,
    REAL_CST,
    COMPLEX_CST,
    VECTOR_CST,
    STRING_CST,
    FUNCTION_DECL,
    LABEL_DECL,
    CONST_DECL,
    TYPE_DECL,
    VAR_DECL,
    PARM_DECL,
    RESULT_DECL,
    FIELD_DECL,
    NAMESPACE_DECL,
    COMPONENT_REF,
    BIT_FIELD_REF,
    INDIRECT_REF,
    BUFFER_REF,
    ARRAY_REF,
    ARRAY_RANGE_REF,
    VTABLE_REF,
    CONSTRUCTOR,
    COMPOUND_EXPR,
    MODIFY_EXPR,
    INIT_EXPR,
    TARGET_EXPR,
    COND_EXPR,
    BIND_EXPR,
    CALL_EXPR,
    METHOD_CALL_EXPR,
    WITH_CLEANUP_EXPR,
    CLEANUP_POINT_EXPR,
    PLACEHOLDER_EXPR,
    WITH_RECORD_EXPR,
    PLUS_EXPR,
    MINUS_EXPR,
    MULT_EXPR,
    TRUNC_DIV_EXPR,
    CEIL_DIV_EXPR,
    FLOOR_DIV_EXPR,
    ROUND_DIV_EXPR,
    TRUNC_MOD_EXPR,
    CEIL_MOD_EXPR,
    FLOOR_MOD_EXPR,
    ROUND_MOD_EXPR,
    RDIV_EXPR,
    EXACT_DIV_EXPR,
    FIX_TRUNC_EXPR,
    FIX_CEIL_EXPR,
    FIX_FLOOR_EXPR,
    FIX_ROUND_EXPR,
    FLOAT_EXPR,
    NEGATE_EXPR,
    MIN_EXPR,
    MAX_EXPR,
    ABS_EXPR,
    FFS_EXPR,
    LSHIFT_EXPR,
    RSHIFT_EXPR,
    LROTATE_EXPR,
    RROTATE_EXPR,
    BIT_IOR_EXPR,
    BIT_XOR_EXPR,
    BIT_AND_EXPR,
    BIT_ANDTC_EXPR,
    BIT_NOT_EXPR,
    TRUTH_ANDIF_EXPR,
    TRUTH_ORIF_EXPR,
    TRUTH_AND_EXPR,
    TRUTH_OR_EXPR,
    TRUTH_XOR_EXPR,
    TRUTH_NOT_EXPR,
    LT_EXPR,
    LE_EXPR,
    GT_EXPR,
    GE_EXPR,
    EQ_EXPR,
    NE_EXPR,
    UNORDERED_EXPR,
    ORDERED_EXPR,
    UNLT_EXPR,
    UNLE_EXPR,
    UNGT_EXPR,
    UNGE_EXPR,
    UNEQ_EXPR,
    IN_EXPR,
    SET_LE_EXPR,
    CARD_EXPR,
    RANGE_EXPR,
    CONVERT_EXPR,
    NOP_EXPR,
    NON_LVALUE_EXPR,
    VIEW_CONVERT_EXPR,
    SAVE_EXPR,
    UNSAVE_EXPR,
    RTL_EXPR,
    ADDR_EXPR,
    REFERENCE_EXPR,
    ENTRY_VALUE_EXPR,
    FDESC_EXPR,
    COMPLEX_EXPR,
    CONJ_EXPR,
    REALPART_EXPR,
    IMAGPART_EXPR,
    PREDECREMENT_EXPR,
    PREINCREMENT_EXPR,
    POSTDECREMENT_EXPR,
    POSTINCREMENT_EXPR,
    VA_ARG_EXPR,
    TRY_CATCH_EXPR,
    TRY_FINALLY_EXPR,
    GOTO_SUBROUTINE_EXPR,
    LABEL_EXPR,
    GOTO_EXPR,
    RETURN_EXPR,
    EXIT_EXPR,
    LOOP_EXPR,
    LABELED_BLOCK_EXPR,
    EXIT_BLOCK_EXPR,
    EXPR_WITH_FILE_LOCATION,
    SWITCH_EXPR,
    EXC_PTR_EXPR,
    LAST_AND_UNUSED_TREE_CODE
};

struct tree_common {
    tree chain;
    tree type;
    enum tree_code code : 8;
    unsigned int side_effects_flag : 1;
    unsigned int constant_flag : 1;
    unsigned int addressable_flag : 1;
    unsigned int volatile_flag : 1;
    unsigned int readonly_flag : 1;
    unsigned int unsigned_flag : 1;
    unsigned int asm_written_flag : 1;
    unsigned int unused_0 : 1;
    unsigned int used_flag : 1;
    unsigned int nothrow_flag : 1;
    unsigned int static_flag : 1;
    unsigned int public_flag : 1;
    unsigned int private_flag : 1;
    unsigned int protected_flag : 1;
    unsigned int bounded_flag : 1;
    unsigned int deprecated_flag : 1;
    unsigned int lang_flag_0 : 1;
    unsigned int lang_flag_1 : 1;
    unsigned int lang_flag_2 : 1;
    unsigned int lang_flag_3 : 1;
    unsigned int lang_flag_4 : 1;
    unsigned int lang_flag_5 : 1;
    unsigned int lang_flag_6 : 1;
    unsigned int unused_1 : 1;
};

struct tree_block {
    struct tree_common common;
    unsigned int handler_block_flag : 1;
    unsigned int abstract_flag : 1;
    unsigned int block_num : 30;
    tree vars;
    tree subblocks;
    tree supercontext;
    tree abstract_origin;
    tree fragment_origin;
    tree fragment_chain;
};

union tree_node {
    struct tree_common common;
    struct tree_block block;
};

tree link;
tree subblocks;
tree block;

static const int DATA_SIZE = 1 << 20; // ~1MB of data

void init_vars() {
    block = (tree) calloc(1, sizeof(struct tree_block));
    block->common.code = BLOCK;
    
    // Allocate a chain of blocks to simulate subblocks
    tree *prev_ptr = &subblocks;
    for (int i = 0; i < DATA_SIZE / sizeof(struct tree_block); i++) {
        tree t = (tree) calloc(1, sizeof(struct tree_block));
        t->common.code = BLOCK;
        t->block.block_num = i;
        *prev_ptr = t;
        prev_ptr = &t->common.chain;
    }
    *prev_ptr = NULL; // terminate the chain
}