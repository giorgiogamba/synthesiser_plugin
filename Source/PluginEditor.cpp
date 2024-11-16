// Copyright Giorgio Gamba, 2024

#include "PluginProcessor.h"
#include "PluginEditor.h"

Synthesiser_pluginAudioProcessorEditor::Synthesiser_pluginAudioProcessorEditor (Synthesiser_pluginAudioProcessor& p)
    : AudioProcessorEditor (&p)
    , audioProcessor (p)
    , adsrComponent(audioProcessor.getAudioProcessorValueTreeState())
{
    setSize (400, 300);
    
    oscillatorWaveformsComboBoxAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getAudioProcessorValueTreeState(), "OSC", oscillatorWaveformsComboBox);
    
    addAndMakeVisible(adsrComponent);
}

Synthesiser_pluginAudioProcessorEditor::~Synthesiser_pluginAudioProcessorEditor()
{
}

void Synthesiser_pluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void Synthesiser_pluginAudioProcessorEditor::resized()
{
    adsrComponent.setBounds(getWidth() / 2, 0, getWidth() / 2, getHeight());
}
