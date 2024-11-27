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
    OscillatorComponent
        ( juce::AudioProcessorValueTreeState& apvts
        , juce::String waveTypeSelectorID
        , juce::String fmFrequencyID
        , juce::String fmDepthID );
    
    ~OscillatorComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    juce::ComboBox oscillatorWaveTypeSelector;
    
    juce::Slider fmFrequencySlider;
    juce::Slider fmDepthSlider;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> fmFrequecySliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> fmDepthSliderAttachment;
    
    juce::Label fmFrequencySliderLabel {"FM Frequency"};
    juce::Label fmDepthSliderLabel {"FM Depth"};
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscillatorWaveTypeSelectorAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorComponent)
};
