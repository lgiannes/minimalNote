# make cmakelists for this project
# you need the class Note and Notebook for now, then I will make all the executable

cmake_minimum_required(VERSION 3.5)
# Define project
project( MyNoteBook )

# Define includes
include_directories(./inc)

# Define sources
set(SOURCES
    src/Note.cxx
    src/Notebook.cxx
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Define executable
add_executable(MyNoteBook app/MyNotebook.cxx ${SOURCES})
add_executable(shownotebook app/showNotebook.cxx ${SOURCES})
add_executable(createnotebook app/createNotebook.cxx ${SOURCES})
add_executable(addnote app/addNote.cxx ${SOURCES})
add_executable(cleannotebook app/cleanNotebook.cxx ${SOURCES})

# Define C++11 standard
set_property(TARGET MyNoteBook PROPERTY CXX_STANDARD 14)
set_property(TARGET shownotebook PROPERTY CXX_STANDARD 14)
set_property(TARGET createnotebook PROPERTY CXX_STANDARD 14)
set_property(TARGET addnote PROPERTY CXX_STANDARD 14)
set_property(TARGET cleannotebook PROPERTY CXX_STANDARD 14)

# options
add_compile_options(-Wall -Wextra -Wpedantic -Werror -std=c++14)

