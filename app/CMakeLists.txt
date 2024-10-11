project(app)

file(GLOB app_SRC CONFIGURE_DEPENDS
    "include/*"
    "src/*"
)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
qt5_add_resources(RESOURCES resources/resources.qrc)

add_library(${PROJECT_NAME} STATIC ${app_SRC} ${RESOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Widgets core)
