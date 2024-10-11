cmake_minimum_required(VERSION 3.16)
project(GlobalNetworkCodes)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp)

if(WIN32 AND (NOT EXISTS "${CMAKE_BINARY_DIR}/Qt5Cored.dll" OR
              NOT EXISTS "${CMAKE_BINARY_DIR}/Qt5Guid.dll" OR
              NOT EXISTS "${CMAKE_BINARY_DIR}/Qt5Widgetsd.dll" OR
              NOT EXISTS "${CMAKE_BINARY_DIR}/platforms/qwindowsd.dll"))
       
    set(QT_DIR "C:/Qt/5.15.0/msvc2019_64")

    execute_process(
        COMMAND ${CMAKE_COMMAND} -E env cmd /c "${CMAKE_SOURCE_DIR}/setup.sh" "${CMAKE_BINARY_DIR}" "${CMAKE_SOURCE_DIR}" "${QT_DIR}"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()

add_subdirectory(app)
add_subdirectory(core)
add_subdirectory(external/sqlite3)

target_link_libraries(${PROJECT_NAME} PUBLIC core sqlite3 app)
