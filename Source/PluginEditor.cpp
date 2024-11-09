// Copyright Giorgio Gamba, 2024

#include "PluginProcessor.h"
#include "PluginEditor.h"

Synthesiser_pluginAudioProcessorEditor::Synthesiser_pluginAudioProcessorEditor (Synthesiser_pluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
    
    adsrFilterAttackSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAudioProcessorValueTreeState(), "ATTACK", adsrFilterAttackSlider);
    adsrFilterDecaySliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAudioProcessorValueTreeState(), "DECAY", adsrFilterDecaySlider);
    adsrFilterSustainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAudioProcessorValueTreeState(), "SUSTAIN", adsrFilterSustainSlider);
    adsrFilterReleaseSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAudioProcessorValueTreeState(), "RELEASE", adsrFilterReleaseSlider);
    
    oscillatorWaveformsComboBoxAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getAudioProcessorValueTreeState(), "OSC", oscillatorWaveformsComboBox);
}

Synthesiser_pluginAudioProcessorEditor::~Synthesiser_pluginAudioProcessorEditor()
{
}

void Synthesiser_pluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void Synthesiser_pluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
