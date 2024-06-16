cmake_minimum_required(VERSION 3.16)
project(tetris)

include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v3.0.0
)


FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

project(FTXUI_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(tetris main.cpp
        gameBoard.cpp
        gameBoard.h
        structs.cpp
        structs.h
        gameDebugDisplay.cpp
        gameDebugDisplay.h
)

target_link_libraries(tetris
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component # Not needed for this example.
        ${LUA_LIBRARIES}
)