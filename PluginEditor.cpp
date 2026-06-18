#include "PluginEditor.h"

BabySitterAudioProcessorEditor::BabySitterAudioProcessorEditor (BabySitterAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (300, 150);
    volSlider.setSliderStyle (juce::Slider::LinearVertical);
    volSlider.setRange (0.0, 1.0, 0.01);
    volSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible (volSlider);

    volAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (
        audioProcessor.apvts, "Volume", volSlider);
}

BabySitterAudioProcessorEditor::~BabySitterAudioProcessorEditor() {}

void BabySitterAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::darkgrey);
    g.setColour (juce::Colours::white);
    g.setFont (20.0f);
    g.drawText ("BabySitter", getLocalBounds().removeFromTop (30), juce::Justification::centred);
}

void BabySitterAudioProcessorEditor::resized()
{
    auto area = getLocalBounds();
    area.removeFromTop (30);
    volSlider.setBounds (area.reduced (40));
}
