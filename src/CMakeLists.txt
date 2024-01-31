set(SOURCES
   main.cpp
   file_reader.cpp
   file_writer.cpp
   words_counter.cpp
)

add_executable(${CMAKE_PROJECT_NAME}
   ${SOURCES}
)