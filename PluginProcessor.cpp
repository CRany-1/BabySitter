#include "PluginProcessor.h"
#include "PluginEditor.h"

BabySitterAudioProcessor::BabySitterAudioProcessor()
    : AudioProcessor (BusesProperties().withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)),
      apvts (*this, nullptr, "Parameters", createParameterLayout())
{
}

BabySitterAudioProcessor::~BabySitterAudioProcessor() {}

juce::AudioProcessorValueTreeState::ParameterLayout BabySitterAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    layout.add (std::make_unique<juce::AudioParameterFloat> ("Volume", "Volume", 0.0f, 1.0f, 0.8f));
    return layout;
}

const juce::String BabySitterAudioProcessor::getName() const { return "BabySitter"; }
bool BabySitterAudioProcessor::acceptsMidi() const { return false; }
bool BabySitterAudioProcessor::producesMidi() const { return false; }
double BabySitterAudioProcessor::getTailLengthSeconds() const { return 0.0; }
int BabySitterAudioProcessor::getNumPrograms() { return 1; }
int BabySitterAudioProcessor::getCurrentProgram() { return 0; }
void BabySitterAudioProcessor::setCurrentProgram (int) {}
const juce::String BabySitterAudioProcessor::getProgramName (int) { return {}; }
void BabySitterAudioProcessor::changeProgramName (int, const juce::String&) {}
void BabySitterAudioProcessor::prepareToPlay (double, int) {}
void BabySitterAudioProcessor::releaseResources() {}
void BabySitterAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer&)
{
    auto* volParam = apvts.getRawParameterValue ("Volume");
    float vol = volParam != nullptr ? volParam->load() : 0.8f;
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        auto* data = buffer.getWritePointer (ch);
        for (int s = 0; s < buffer.getNumSamples(); ++s)
            data[s] *= vol;
    }
}

bool BabySitterAudioProcessor::hasEditor() const { return true; }
juce::AudioProcessorEditor* BabySitterAudioProcessor::createEditor() { return new BabySitterAudioProcessorEditor (*this); }

void BabySitterAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = apvts.copyState();
    std::unique_ptr<juce::XmlElement> xml (state.createXml());
    copyXmlToBinary (*xml, destData);
}

void BabySitterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName (apvts.state.getType()))
            apvts.replaceState (juce::ValueTree::fromXml (*xmlState));
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() { return new BabySitterAudioProcessor(); }
