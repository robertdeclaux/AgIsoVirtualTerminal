cmake_minimum_required(VERSION 3.16)

project(
  "AgISOUniversalTerminal"
  LANGUAGES CXX
  VERSION 0.0.1)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(JUCE MODULE)
find_package(CAN_Stack MODULE)
find_package(Threads REQUIRED)

# set(CAN_DRIVER "TouCAN") Set this to be whatever your CAN driver is
# add_subdirectory(ISO11783-CAN-Stack)

juce_add_gui_app(
  AgISOUniversalTerminal
  # ICON_BIG ...                      # ICON_* arguments specify a path to an
  # image file to use as an icon ICON_SMALL ...
  COMPANY_NAME
  "Open-Agriculture"
  PRODUCT_NAME
  "AgISOUniversalTerminal")

juce_generate_juce_header(AgISOUniversalTerminal)

target_sources(
  AgISOUniversalTerminal
  PRIVATE src/Main.cpp
          "src/ServerMainComponent.cpp"
          "src/DataMaskComponent.cpp"
          "src/WorkingSetSelectorComponent.cpp"
          "src/PictureGraphicComponent.cpp"
          "src/WorkingSetComponent.cpp"
          "src/AlarmMaskComponent.cpp"
          "src/DataMaskRenderAreaComponent.cpp"
          "src/JuceManagedWorkingSetCache.cpp"
          "src/OutputRectangleComponent.cpp"
          "src/OutputStringComponent.cpp"
          "src/ButtonComponent.cpp"
          "src/ContainerComponent.cpp"
          "src/ObjectPointerComponent.cpp"
          "src/OutputNumberComponent.cpp"
          "src/SoftkeyMaskRenderArea.cpp"
          "src/KeyComponent.cpp"
          "src/SoftKeyMaskComponent.cpp"
          "src/OutputMeterComponent.cpp"
          "src/InputBooleanComponent.cpp"
          "src/LoggerComponent.cpp"
          "src/InputNumberComponent.cpp"
          "src/OutputEllipseComponent.cpp"
          "src/OutputLineComponent.cpp"
          "src/OutputLinearBarGraphComponent.cpp"
          "src/OutputPolygonComponent.cpp"
          "src/InputListComponent.cpp")

target_include_directories(AgISOUniversalTerminal
                           PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)

target_link_libraries(
  AgISOUniversalTerminal
  PRIVATE juce::juce_gui_extra isobus::Isobus isobus::HardwareIntegration
          isobus::Utility
  PUBLIC juce::juce_recommended_config_flags juce::juce_recommended_lto_flags
         juce::juce_recommended_warning_flags)