project(Knights)

find_package(KDE4 REQUIRED)
find_package(LibKDEGames REQUIRED)
include (KDE4Defaults)
# TODO: check for gnuchess

set(CMAKE_CXX_FLAGS_PROFILE "-fprofile-arcs -ftest-coverage -pg")
add_definitions( -DQT_NO_CAST_FROM_ASCII )
add_definitions( -DQT_NO_CAST_TO_ASCII )

include_directories( ${KDE4_INCLUDES} ${QT_INCLUDES} ${KDEGAMES_INCLUDE_DIRS} )

if (${KDE_VERSION} VERSION_GREATER "4.5.60")
    option(KGR "Use KGameRenderer" ON)
endif (${KDE_VERSION} VERSION_GREATER "4.5.60")

set(QT_VERSION "${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}.${QT_VERSION_PATCH}")
if (${QT_VERSION} VERSION_GREATER "4.6.0")
    option(ANIMATIONS "Use Qt Animations" ON)
endif()

add_subdirectory( src )
add_subdirectory( icons )
add_subdirectory( themes )
add_subdirectory( doc )
