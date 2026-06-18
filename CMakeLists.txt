cmake_minimum_required(VERSION 3.15)
project(BabySitter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# 使用本地克隆的 JUCE
add_subdirectory(JUCE)

juce_add_plugin(BabySitter
    COMPANY_NAME "MyCompany"
    FORMATS VST3
    PRODUCT_NAME "BabySitter"
    VERSION 1.0.0
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
)

target_sources(BabySitter PRIVATE
    PluginProcessor.h
    PluginProcessor.cpp
    PluginEditor.h
    PluginEditor.cpp
)
