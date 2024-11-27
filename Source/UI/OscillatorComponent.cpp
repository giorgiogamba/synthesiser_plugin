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
OscillatorComponent::OscillatorComponent
 ( juce::AudioProcessorValueTreeState& apvts
 , juce::String waveTypeSelectorID
 , juce::String fmFrequencyID
 , juce::String fmDepthID )
{
    oscillatorWaveTypeSelectorAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>
        ( apvts
         , waveTypeSelectorID
         , oscillatorWaveTypeSelector );
    
    juce::StringArray wavetypeChoices {"Sine", "Saw", "Square"};
    oscillatorWaveTypeSelector.addItemList(wavetypeChoices, 1);
    addAndMakeVisible(oscillatorWaveTypeSelector);
    
    fmFrequencySlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    fmFrequencySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(fmFrequencySlider);
    
    fmFrequecySliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, fmFrequencyID, fmFrequencySlider);
    
    fmDepthSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    
    fmFrequencySliderLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    fmFrequencySliderLabel.setJustificationType(juce::Justification::centred);
    fmFrequencySliderLabel.setFont(15.f);
    addAndMakeVisible(fmFrequencySliderLabel);
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
    fmFrequencySlider.setBounds(0, 80, 100, 90);
    fmFrequencySliderLabel.setBounds(fmFrequencySlider.getX(),  fmFrequencySlider.getY() - 20, fmFrequencySlider,getWidth(), 20);;
}
