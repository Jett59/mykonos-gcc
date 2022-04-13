#ifndef GCC_CONFIG_MYKONOS_H
#define GCC_CONFIG_MYKONOS_H

#undef TARGET_MYKONOS
#define TARGET_MYKONOS 1

// Default arguments
#undef LIB_SPEC
// Link the standard library
#define LIB_SPEC "-lc"

// Files to link before user files
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "crt1.o%s"

// Files to link after user files
#undef ENDFILE_SPEC
#define ENDFILE_SPEC ""

// Linker arguments
#undef LINK_SPEC
// 4k pages
#define LINK_SPEC "-z max-page-size=4096"

// Preprocessor builtins
#undef TARGET_OS_CPP_BUILTINS
// __MYKONOS__, __unix__
#define TARGET_OS_CPP_BUILTINS() \
  do { \
    builtin_define("__MYKONOS__"); \
    builtin_define("__unix__"); \
    builtin_assert("system=mykonos"); \
  }while(0)

#endif