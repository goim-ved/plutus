function(plutus_set_warnings target_name)
    set(MSVC_WARNINGS
        /W4
        /permissive-
    )
    
    set(CLANG_WARNINGS
        -Wall 
        -Wextra 
        -Wpedantic
        -Wshadow
        -Wnon-virtual-dtor 
        -Wold-style-cast 
        -Wcast-align 
        -Wunused
        -Woverloaded-virtual 
        -Wcoversion 
        -Wsign-conversion 
        -Wnull-dereference
        -Wformat=2
    )

    set(GCC_WARNINGS
        ${CLANG_WARNINGS}
        -Wmisleading-indentation
        -Wduplicated-cond 
        -Wduplicated-branches
        -Wlogical-op 
        -Wuseless-cast 
    )

    if(MSVC)
        set(PROJECT_WARNINGS ${MSVC_WARNINGS})
    elseif(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
        set(PROJECT_WARNINGS ${CLANG_WARNINGS})
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(PROJECT_WARNINGS ${GCC_WARNINGS})
    endif()

    target_compile_options(${target_name} PRIVATE ${PROJECT_WARNINGS})
endfunction()
    