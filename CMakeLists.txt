project(non-guillotine-cutting)

add_executable(non-guillotine-cutting main.c config.c heuristics/rec.c heuristics/heuristic.c)

install(TARGETS non-guillotine-cutting RUNTIME DESTINATION bin)

list(APPEND CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(CMAKE_C_COMPILER "/usr/bin/gcc")

add_subdirectory(in)

add_subdirectory(heuristics)