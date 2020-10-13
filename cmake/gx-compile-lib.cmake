FUNCTION(GX_COMPILE_LIB DIR)
    SET(BUILD_DIR ${DIR}-build)
    FILE(REMOVE_RECURSE ${BUILD_DIR})
    FILE(MAKE_DIRECTORY ${BUILD_DIR})
    EXECUTE_PROCESS(COMMAND cmake -H${DIR} -B${BUILD_DIR} -DCMAKE_BUILD_TYPE=Release)
    EXECUTE_PROCESS(COMMAND cmake --build ${BUILD_DIR} --config Release)
ENDFUNCTION(GX_COMPILE_LIB)