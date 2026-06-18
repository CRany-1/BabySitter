# BabySittercmake_minimum_required(VERSION 3.15)
project(BabySitter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 自动下载 JUCE
include(FetchContent)
FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG 7.0.5
)
FetchContent_MakeAvailable(JUCE)

juce_add_plugin(BabySitter
    COMPANY_NAME "MyCompany"
    PLUGIN_MANUFACTURER_CODE Juce
    PLUGIN_CODE Juce
    FORMATS VST3
    PRODUCT_NAME "BabySitter"
    VERSION 1.0.0
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_NAME "BabySitter"
)

target_sources(BabySitter PRIVATE
    PluginProcessor.h
    PluginProcessor.cpp
    PluginEditor.h
    PluginEditor.cpp
)
