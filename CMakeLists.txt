cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_CXX_STANDARD 14)
set(QT_MIN_VERSION "5.7.0")

project(ghoaepp)

# application name
set(APPLICATION_ID "ga.ghsq.ghoaepp")
set(APPLICATION_NAME "ghoaepp")
set(APPLICATION_DISPLAY_NAME "GHO Äpp")
set(APPLICATION_DESCRIPTION "Ein einfacher Vertretungsplanleser")


# Version
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)
set(VERSION_EXTRA "dev")
set(VERSION_STRING "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
if(VERSION_EXTRA)
	set(VERSION_STRING ${VERSION_STRING}-${VERSION_EXTRA})
endif()

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc, uic and rcc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# CMake modules include
include(FeatureSummary)
include(GNUInstallDirs)

#
# Dependecies
#

# Find packages
find_package(Qt5 ${QT_MIN_VERSION} REQUIRED NO_MODULE COMPONENTS Core Qml Quick Network QuickControls2)
find_package(KF5Kirigami2 REQUIRED)

#
# Load submodules
#

# Main kaidan sources
include("${CMAKE_SOURCE_DIR}/src/CMakeLists.txt")


#
# Sources / Resources
#

add_executable(${PROJECT_NAME}
        ${APP_SOURCES}
        qml.qrc
)


#
# Linker Flags
#

target_link_libraries(${PROJECT_NAME}
	Qt5::Core
	Qt5::Qml
	Qt5::Quick
)


#
# Global C++ variables
#

target_compile_definitions(${PROJECT_NAME} PRIVATE
	APPLICATION_ID="${APPLICATION_ID}"
	APPLICATION_NAME="${APPLICATION_NAME}"
	APPLICATION_DISPLAY_NAME="${APPLICATION_DISPLAY_NAME}"
	APPLICATION_DESCRIPTION="${APPLICATION_DESCRIPTION}"

	VERSION_STRING="${VERSION_STRING}"

	DEBUG_SOURCE_PATH="${CMAKE_SOURCE_DIR}"
)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
