/*
  ==============================================================================

    OscillatorComponent.h
    Created: 16 Nov 2024 5:15:39pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class OscillatorComponent  : public juce::Component
{
public:
    OscillatorComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveTypeSelectorID);
    ~OscillatorComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    juce::ComboBox oscillatorWaveTypeSelector;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscillatorWaveTypeSelectorAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorComponent)
};
