add_subdirectory(utils)

AUX_SOURCE_DIRECTORY(. DIR_SRC)
ADD_LIBRARY (obfus ${DIR_SRC})