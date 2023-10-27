set(APP_NAME "task")
set(APP_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/serializer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/verifier.cpp)

set(APP_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${APP_NAME} ${APP_SOURCES})
target_include_directories(${APP_NAME} PRIVATE ${APP_INCLUDES})
