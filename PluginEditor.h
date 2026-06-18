#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class BabySitterAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    BabySitterAudioProcessorEditor (BabySitterAudioProcessor&);
    ~BabySitterAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    BabySitterAudioProcessor& audioProcessor;
    juce::Slider volSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> volAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BabySitterAudioProcessorEditor)
};
