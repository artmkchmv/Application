cmake_minimum_required(VERSION 3.10)
project(Application)

set(SFML_DIR SFML-2.6.2/lib/cmake/SFML)

find_package(SFML 2.6.2 REQUIRED graphics window system)

link_directories(SFML-2.6.2/lib)

include_directories(include SFML-2.6.2/include)

set(SOURCES
    src/Button.cpp
    src/FinishState.cpp
    src/main.cpp
    src/MainWindow.cpp
    src/Reel.cpp
    src/Slot.cpp
    src/SlotMachine.cpp
    src/SpinState.cpp
    src/WaitState.cpp
)

add_executable(Application ${SOURCES})

configure_file(${CMAKE_SOURCE_DIR}/assets/Arial.ttf ${CMAKE_BINARY_DIR}/assets/Arial.ttf COPYONLY)

target_link_libraries(Application 
    sfml-graphics 
    sfml-window 
    sfml-system 
    opengl32 
    freetype 
    winmm 
    gdi32
)

add_custom_command(TARGET Application POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/SFML-2.6.2/bin $<TARGET_FILE_DIR:Application>
)
