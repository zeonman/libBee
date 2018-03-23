set(BEE_DATA_STRUCTURE_INCLUDE_PATH ${BEE_INCLUDE_PATH}/bee/data_structure)

set(DATA_STRUCTURE_FILES
  ${BEE_DATA_STRUCTURE_INCLUDE_PATH}/SinglyList.h
  src/SinglyList.cpp
  ${BEE_DATA_STRUCTURE_INCLUDE_PATH}/List.h
  src/List.cpp
  ${BEE_DATA_STRUCTURE_INCLUDE_PATH}/NodeStack.h
  src/NodeStack.cpp
  ${BEE_DATA_STRUCTURE_INCLUDE_PATH}/NodeQueue.h
  src/NodeQueue.cpp
  ${BEE_DATA_STRUCTURE_INCLUDE_PATH}/half_thread_safe/htsNodeStack.h
  src/half_thread_safe/htsNodeStack.cpp
  ${BEE_DATA_STRUCTURE_INCLUDE_PATH}/thread_safe/tsNodeStack.h
  src/thread_safe/tsNodeStack.cpp
)

add_library(data_structure STATIC
  ${DATA_STRUCTURE_FILES}
)