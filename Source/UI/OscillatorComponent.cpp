/*
  ==============================================================================

    OscillatorComponent.cpp
    Created: 16 Nov 2024 5:15:39pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscillatorComponent.h"

//==============================================================================
OscillatorComponent::OscillatorComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveTypeSelectorID)
{
    oscillatorWaveTypeSelectorAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>
        ( apvts
         , waveTypeSelectorID
         , oscillatorWaveTypeSelector );
    
    juce::StringArray wavetypeChoices {"Sine", "Saw", "Square"};
    oscillatorWaveTypeSelector.addItemList(wavetypeChoices, 1);
    addAndMakeVisible(oscillatorWaveTypeSelector);
}

OscillatorComponent::~OscillatorComponent()
{
}

void OscillatorComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void OscillatorComponent::resized()
{
    oscillatorWaveTypeSelector.setBounds(0, 0, 90, 20);
}
