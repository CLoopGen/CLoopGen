#include <stdio.h>

#include <inttypes.h>

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


typedef struct rtx_def *rtx;

struct {
    unsigned long low;
    long high;
};


struct tree_int_cst {
    struct tree_common common;
    rtx rtl;
    struct {
        unsigned long low;
        long high;
    } int_cst;
};


typedef struct {
    long r[3];
} realvaluetype;

struct tree_real_cst {
    struct tree_common common;
    rtx rtl;
    realvaluetype real_cst;
};


struct tree_vector {
    struct tree_common common;
    rtx rtl;
    tree elements;
};


struct tree_string {
    struct tree_common common;
    rtx rtl;
    int length;
    const char *pointer;
};


struct tree_complex {
    struct tree_common common;
    rtx rtl;
    tree real;
    tree imag;
};


struct ht_identifier {
    unsigned int len;
    const unsigned char *str;
};


struct tree_identifier {
    struct tree_common common;
    struct ht_identifier id;
};


enum machine_mode {
    VOIDmode,
    BImode,
    QImode,
    HImode,
    SImode,
    DImode,
    TImode,
    OImode,
    PQImode,
    PHImode,
    PSImode,
    PDImode,
    QFmode,
    HFmode,
    TQFmode,
    SFmode,
    DFmode,
    XFmode,
    TFmode,
    QCmode,
    HCmode,
    SCmode,
    DCmode,
    XCmode,
    TCmode,
    CQImode,
    CHImode,
    CSImode,
    CDImode,
    CTImode,
    COImode,
    V2QImode,
    V2HImode,
    V2SImode,
    V2DImode,
    V4QImode,
    V4HImode,
    V4SImode,
    V4DImode,
    V8QImode,
    V8HImode,
    V8SImode,
    V8DImode,
    V16QImode,
    V2SFmode,
    V2DFmode,
    V4SFmode,
    V4DFmode,
    V8SFmode,
    V8DFmode,
    V16SFmode,
    BLKmode,
    CCmode,
    CCGCmode,
    CCGOCmode,
    CCNOmode,
    CCZmode,
    CCFPmode,
    CCFPUmode,
    MAX_MACHINE_MODE
};


enum built_in_class {
    NOT_BUILT_IN = 0,
    BUILT_IN_FRONTEND,
    BUILT_IN_MD,
    BUILT_IN_NORMAL
};


enum built_in_function {
    BUILT_IN_ALLOCA,
    BUILT_IN_ABS,
    BUILT_IN_LABS,
    BUILT_IN_FABS,
    BUILT_IN_FABSF,
    BUILT_IN_FABSL,
    BUILT_IN_LLABS,
    BUILT_IN_IMAXABS,
    BUILT_IN_CONJ,
    BUILT_IN_CONJF,
    BUILT_IN_CONJL,
    BUILT_IN_CREAL,
    BUILT_IN_CREALF,
    BUILT_IN_CREALL,
    BUILT_IN_CIMAG,
    BUILT_IN_CIMAGF,
    BUILT_IN_CIMAGL,
    BUILT_IN_BZERO,
    BUILT_IN_BCMP,
    BUILT_IN_FFS,
    BUILT_IN_INDEX,
    BUILT_IN_RINDEX,
    BUILT_IN_MEMCPY,
    BUILT_IN_MEMCMP,
    BUILT_IN_MEMSET,
    BUILT_IN_STRCAT,
    BUILT_IN_STRNCAT,
    BUILT_IN_STRCPY,
    BUILT_IN_STRNCPY,
    BUILT_IN_STRCMP,
    BUILT_IN_STRNCMP,
    BUILT_IN_STRLEN,
    BUILT_IN_STRSTR,
    BUILT_IN_STRPBRK,
    BUILT_IN_STRSPN,
    BUILT_IN_STRCSPN,
    BUILT_IN_STRCHR,
    BUILT_IN_STRRCHR,
    BUILT_IN_SQRT,
    BUILT_IN_SIN,
    BUILT_IN_COS,
    BUILT_IN_SQRTF,
    BUILT_IN_SINF,
    BUILT_IN_COSF,
    BUILT_IN_SQRTL,
    BUILT_IN_SINL,
    BUILT_IN_COSL,
    BUILT_IN_SAVEREGS,
    BUILT_IN_CLASSIFY_TYPE,
    BUILT_IN_NEXT_ARG,
    BUILT_IN_ARGS_INFO,
    BUILT_IN_CONSTANT_P,
    BUILT_IN_FRAME_ADDRESS,
    BUILT_IN_RETURN_ADDRESS,
    BUILT_IN_AGGREGATE_INCOMING_ADDRESS,
    BUILT_IN_APPLY_ARGS,
    BUILT_IN_APPLY,
    BUILT_IN_RETURN,
    BUILT_IN_SETJMP,
    BUILT_IN_LONGJMP,
    BUILT_IN_TRAP,
    BUILT_IN_PREFETCH,
    BUILT_IN_PUTCHAR,
    BUILT_IN_PUTS,
    BUILT_IN_PRINTF,
    BUILT_IN_FPUTC,
    BUILT_IN_FPUTS,
    BUILT_IN_FWRITE,
    BUILT_IN_FPRINTF,
    BUILT_IN_PUTCHAR_UNLOCKED,
    BUILT_IN_PUTS_UNLOCKED,
    BUILT_IN_PRINTF_UNLOCKED,
    BUILT_IN_FPUTC_UNLOCKED,
    BUILT_IN_FPUTS_UNLOCKED,
    BUILT_IN_FWRITE_UNLOCKED,
    BUILT_IN_FPRINTF_UNLOCKED,
    BUILT_IN_ISGREATER,
    BUILT_IN_ISGREATEREQUAL,
    BUILT_IN_ISLESS,
    BUILT_IN_ISLESSEQUAL,
    BUILT_IN_ISLESSGREATER,
    BUILT_IN_ISUNORDERED,
    BUILT_IN_UNWIND_INIT,
    BUILT_IN_DWARF_CFA,
    BUILT_IN_DWARF_FP_REGNUM,
    BUILT_IN_INIT_DWARF_REG_SIZES,
    BUILT_IN_FROB_RETURN_ADDR,
    BUILT_IN_EXTRACT_RETURN_ADDR,
    BUILT_IN_EH_RETURN,
    BUILT_IN_EH_RETURN_DATA_REGNO,
    BUILT_IN_VARARGS_START,
    BUILT_IN_STDARG_START,
    BUILT_IN_VA_END,
    BUILT_IN_VA_COPY,
    BUILT_IN_EXPECT,
    END_BUILTINS
};


struct {
    unsigned int align : 24;
    unsigned int off_align : 8;
};


union {
    enum built_in_function f;
    long i;
    struct {
        unsigned int align : 24;
        unsigned int off_align : 8;
    } a;
};


struct expr_status {
    int x_pending_stack_adjust;
    int x_inhibit_defer_pop;
    int x_stack_pointer_delta;
    rtx x_saveregs_value;
    rtx x_apply_args_value;
    rtx x_forced_labels;
    rtx x_pending_chain;
};


struct sequence_stack {
    rtx first;
    rtx last;
    tree sequence_rtl_expr;
    struct sequence_stack *next;
};


struct emit_status {
    int x_reg_rtx_no;
    int x_first_label_num;
    rtx x_first_insn;
    rtx x_last_insn;
    tree sequence_rtl_expr;
    struct sequence_stack *sequence_stack;
    int x_cur_insn_uid;
    int x_last_linenum;
    const char *x_last_filename;
    int regno_pointer_align_length;
    unsigned char *regno_pointer_align;
    tree *regno_decl;
    rtx *x_regno_reg_rtx;
};


typedef struct ix86_args {
    int words;
    int nregs;
    int regno;
    int sse_words;
    int sse_nregs;
    int sse_regno;
    int maybe_vaarg;
} CUMULATIVE_ARGS;

struct var_refs_queue {
    rtx modified;
    enum machine_mode promoted_mode;
    int unsignedp;
    struct var_refs_queue *next;
};


struct function {
    struct eh_status *eh;
    struct stmt_status *stmt;
    struct expr_status *expr;
    struct emit_status *emit;
    struct varasm_status *varasm;
    const char *name;
    tree decl;
    struct function *outer;
    int pops_args;
    int args_size;
    int pretend_args_size;
    int outgoing_args_size;
    rtx arg_offset_rtx;
    CUMULATIVE_ARGS args_info;
    rtx return_rtx;
    rtx internal_arg_pointer;
    const char *cannot_inline;
    struct initial_value_struct *hard_reg_initial_vals;
    int x_function_call_count;
    tree x_nonlocal_labels;
    rtx x_nonlocal_goto_handler_slots;
    rtx x_nonlocal_goto_handler_labels;
    rtx x_nonlocal_goto_stack_level;
    rtx x_cleanup_label;
    rtx x_return_label;
    rtx x_save_expr_regs;
    rtx x_stack_slot_list;
    tree x_rtl_expr_chain;
    rtx x_tail_recursion_label;
    rtx x_tail_recursion_reentry;
    rtx x_arg_pointer_save_area;
    rtx x_clobber_return_insn;
    long x_frame_offset;
    tree x_context_display;
    tree x_trampoline_list;
    rtx x_parm_birth_insn;
    rtx x_last_parm_insn;
    unsigned int x_max_parm_reg;
    rtx *x_parm_reg_stack_loc;
    struct temp_slot *x_temp_slots;
    int x_temp_slot_level;
    int x_var_temp_slot_level;
    int x_target_temp_slot_level;
    struct var_refs_queue *fixup_var_refs_queue;
    int inlinable;
    int no_debugging_symbols;
    void *original_arg_vector;
    tree original_decl_initial;
    rtx inl_last_parm_insn;
    int inl_max_label_num;
    int profile_label_no;
    struct machine_function *machine;
    int stack_alignment_needed;
    int preferred_stack_boundary;
    struct language_function *language;
    rtx epilogue_delay_list;
    unsigned int returns_struct : 1;
    unsigned int returns_pcc_struct : 1;
    unsigned int returns_pointer : 1;
    unsigned int needs_context : 1;
    unsigned int calls_setjmp : 1;
    unsigned int calls_longjmp : 1;
    unsigned int calls_alloca : 1;
    unsigned int calls_eh_return : 1;
    unsigned int has_nonlocal_label : 1;
    unsigned int has_nonlocal_goto : 1;
    unsigned int contains_functions : 1;
    unsigned int has_computed_jump : 1;
    unsigned int is_thunk : 1;
    unsigned int instrument_entry_exit : 1;
    unsigned int profile : 1;
    unsigned int limit_stack : 1;
    unsigned int varargs : 1;
    unsigned int stdarg : 1;
    unsigned int x_whole_function_mode_p : 1;
    unsigned int x_dont_save_pending_sizes_p : 1;
    unsigned int uses_const_pool : 1;
    unsigned int uses_pic_offset_table : 1;
    unsigned int uses_eh_lsda : 1;
    unsigned int arg_pointer_save_area_init : 1;
};


union {
    struct function *f;
    rtx r;
    tree t;
    int i;
};


struct tree_decl {
    struct tree_common common;
    const char *filename;
    int linenum;
    unsigned int uid;
    tree size;
    enum machine_mode mode : 8;
    unsigned int external_flag : 1;
    unsigned int nonlocal_flag : 1;
    unsigned int regdecl_flag : 1;
    unsigned int inline_flag : 1;
    unsigned int bit_field_flag : 1;
    unsigned int virtual_flag : 1;
    unsigned int ignored_flag : 1;
    unsigned int abstract_flag : 1;
    unsigned int in_system_header_flag : 1;
    unsigned int common_flag : 1;
    unsigned int defer_output : 1;
    unsigned int transparent_union : 1;
    unsigned int static_ctor_flag : 1;
    unsigned int static_dtor_flag : 1;
    unsigned int artificial_flag : 1;
    unsigned int weak_flag : 1;
    unsigned int non_addr_const_p : 1;
    unsigned int no_instrument_function_entry_exit : 1;
    unsigned int comdat_flag : 1;
    unsigned int malloc_flag : 1;
    unsigned int no_limit_stack : 1;
    enum built_in_class built_in_class : 2;
    unsigned int pure_flag : 1;
    unsigned int pointer_depth : 2;
    unsigned int non_addressable : 1;
    unsigned int user_align : 1;
    unsigned int uninlinable : 1;
    unsigned int lang_flag_0 : 1;
    unsigned int lang_flag_1 : 1;
    unsigned int lang_flag_2 : 1;
    unsigned int lang_flag_3 : 1;
    unsigned int lang_flag_4 : 1;
    unsigned int lang_flag_5 : 1;
    unsigned int lang_flag_6 : 1;
    unsigned int lang_flag_7 : 1;
    union {
        enum built_in_function f;
        long i;
        struct {
            unsigned int align : 24;
            unsigned int off_align : 8;
        } a;
    } u1;
    tree size_unit;
    tree name;
    tree context;
    tree arguments;
    tree result;
    tree initial;
    tree abstract_origin;
    tree assembler_name;
    tree section_name;
    tree attributes;
    rtx rtl;
    rtx live_range_rtl;
    union {
        struct function *f;
        rtx r;
        tree t;
        int i;
    } u2;
    tree saved_tree;
    tree inlined_fns;
    tree vindex;
    long pointer_alias_set;
    struct lang_decl *lang_specific;
};


union {
    int address;
    char *pointer;
};


struct tree_type {
    struct tree_common common;
    tree values;
    tree size;
    tree size_unit;
    tree attributes;
    unsigned int uid;
    unsigned int precision : 9;
    enum machine_mode mode : 7;
    unsigned int string_flag : 1;
    unsigned int no_force_blk_flag : 1;
    unsigned int needs_constructing_flag : 1;
    unsigned int transparent_union_flag : 1;
    unsigned int packed_flag : 1;
    unsigned int restrict_flag : 1;
    unsigned int pointer_depth : 2;
    unsigned int lang_flag_0 : 1;
    unsigned int lang_flag_1 : 1;
    unsigned int lang_flag_2 : 1;
    unsigned int lang_flag_3 : 1;
    unsigned int lang_flag_4 : 1;
    unsigned int lang_flag_5 : 1;
    unsigned int lang_flag_6 : 1;
    unsigned int user_align : 1;
    unsigned int align;
    tree pointer_to;
    tree reference_to;
    union {
        int address;
        char *pointer;
    } symtab;
    tree name;
    tree minval;
    tree maxval;
    tree next_variant;
    tree main_variant;
    tree binfo;
    tree context;
    long alias_set;
    struct lang_type *lang_specific;
};


struct tree_list {
    struct tree_common common;
    tree purpose;
    tree value;
};


struct tree_vec {
    struct tree_common common;
    int length;
    tree a[1];
};


struct tree_exp {
    struct tree_common common;
    int complexity;
    tree operands[1];
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
    struct tree_int_cst int_cst;
    struct tree_real_cst real_cst;
    struct tree_vector vector;
    struct tree_string string;
    struct tree_complex complex;
    struct tree_identifier identifier;
    struct tree_decl decl;
    struct tree_type type;
    struct tree_list list;
    struct tree_vec vec;
    struct tree_exp exp;
    struct tree_block block;
};


extern tree list;
extern unsigned int hashcode;
extern tree tail;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    hashcode = 0;
    tail = list;
    for (; tail; tail = ((tail)->common.chain)) {
        size_t value = (size_t)(((tail)->list.purpose)) & 262143;
        if (value > 1000) {
            hashcode += value;
        } else {
            hashcode += value * 2;
        }
    }
}
