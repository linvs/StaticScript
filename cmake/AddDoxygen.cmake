find_package(Doxygen REQUIRED dot)

if (DOXYGEN_FOUND)
    set(DOXYGEN_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
    set(DOXYGEN_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/doxygen)
    set(DOXYGEN_OUTPUT_LANGUAGE Chinese)
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_EXTRACT_STATIC YES)
    set(DOXYGEN_FORCE_LOCAL_INCLUDES YES)
    set(DOXYGEN_RECURSIVE YES)
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE ${PROJECT_SOURCE_DIR}/README-zh_CN.md)
    set(DOXYGEN_SOURCE_BROWSER YES)
    set(DOXYGEN_STRIP_CODE_COMMENTS NO)
    set(DOXYGEN_REFERENCED_BY_RELATION YES)
    set(DOXYGEN_GENERATE_LATEX NO)
    set(DOXYGEN_MACRO_EXPANSION YES)
    set(DOXYGEN_EXPAND_ONLY_PREDEF YES)
    set(DOXYGEN_ALLEXTERNALS YES)
    set(DOXYGEN_HIDE_UNDOC_RELATIONS NO)
    set(DOXYGEN_TEMPLATE_RELATIONS YES)
    set(DOXYGEN_DOT_TRANSPARENT YES)
    set(DOXYGEN_DOT_MULTI_TARGETS YES)
    doxygen_add_docs(
            doxygen
            ${PROJECT_SOURCE_DIR}/include
            ${PROJECT_SOURCE_DIR}/lib
            ${PROJECT_SOURCE_DIR}/README-zh_CN.md
    )
endif ()