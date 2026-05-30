
add_library(matrix_l)



target_sources(matrix_l
  PRIVATE 
    matrix_cpp.cc

  PUBLIC 
    FILE_SET HEADERS 
    FILES 
      matrix_cpp.hpp
)