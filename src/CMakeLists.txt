add_executable(${PROJECT_NAME})

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES AUTOMOC TRUE
)

target_sources(
  ${PROJECT_NAME} PRIVATE
  main.cc
  tapper.h tapper.cc
  resources.qrc
)

target_link_libraries(
  ${PROJECT_NAME}
  Qt5::Quick
  Qt5::Qml
  Qt5::Gui
  Qt5::QuickControls2
  Qt5::Widgets
  KF5::Kirigami2
)
