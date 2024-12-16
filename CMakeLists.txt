cmake_minimum_required(VERSION 3.10)
project(Application)

# Путь к папке с SFML
set(SFML_DIR SFML-2.6.2/lib/cmake/SFML)

# Поиск библиотеки SFML
find_package(SFML 2.6.2 REQUIRED graphics window system)

# Указываем путь к папке с библиотеками
link_directories(SFML-2.6.2/lib)

# Добавление директорий с заголовочными файлами
include_directories(include SFML-2.6.2/include)

# Источник файлов
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

# Укажите исходные файлы для компиляции
add_executable(Application ${SOURCES})

# Скопировать Arial.ttf в папку с исполняемым файлом
configure_file(${CMAKE_SOURCE_DIR}/assets/Arial.ttf ${CMAKE_BINARY_DIR}/assets/Arial.ttf COPYONLY)

# Линковка с библиотеками SFML
target_link_libraries(Application 
    sfml-graphics 
    sfml-window 
    sfml-system 
    opengl32 
    freetype 
    winmm 
    gdi32
)

# Постсборочный шаг: копируем DLL файлы в директорию с исполняемым файлом
add_custom_command(TARGET Application POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/SFML-2.6.2/bin $<TARGET_FILE_DIR:Application>
)