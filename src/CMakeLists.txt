
cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(mft_ind_main VERSION ${PROJECT_VERSION})

configure_file(
        versiondef.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/versiondef.h
)

add_executable(mft_ind_main main.cpp imatcher.h istatcollector.h matcher.cpp matcher.h imatcher.h istatcollector.h statcollector.cpp statcollector.h istatcollector.h threadedmatcher.h threadedmathcer.cpp using.h)
add_library(mft_ind_lib version.cpp)

set_target_properties(mft_ind_main mft_ind_lib PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

target_include_directories(
        mft_ind_lib
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
        .
)

target_link_libraries(mft_ind_main PRIVATE
        mft_ind_lib
        )

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    target_compile_options(mft_ind_main PRIVATE
            /W4
            )
    target_compile_options(mft_ind_lib PRIVATE
            /W4
            )
else ()
    target_compile_options(mft_ind_main PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(mft_ind_lib PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif()

install(TARGETS mft_ind_main RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT zholu008@gmail.com)

include(CPack)