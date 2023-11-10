cmake_minimum_required(VERSION 3.27.4)
project(bpm)

set(KF_MIN_VERSION "5.111.0")
set(QT_MIN_VERSION "5.15.11")

find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR YES)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(
  Qt5 ${QT_MIN_VERSION}
  REQUIRED
  NO_MODULE
  COMPONENTS
  Core
  Quick
  Test
  Gui
  QuickControls2
  Widgets
)

find_package(
  KF5 ${KF_MIN_VERSION}
  REQUIRED
  COMPONENTS
  Kirigami2
  CoreAddons
)

add_subdirectory(src)

feature_summary(
  WHAT ALL
  INCLUDE_QUIET_PACKAGES
  FATAL_ON_MISSING_REQUIRED_PACKAGES
)
