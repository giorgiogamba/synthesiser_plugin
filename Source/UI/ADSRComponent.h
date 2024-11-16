/*
  ==============================================================================

    ADSRComponent.h
    Created: 15 Nov 2024 6:18:14pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class ADSRComponent  : public juce::Component
{
public:
    ADSRComponent(juce::AudioProcessorValueTreeState& apvts);
    ~ADSRComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    juce::Slider adsrFilterAttackSlider;
    juce::Slider adsrFilterDecaySlider;
    juce::Slider adsrFilterSustainSlider;
    juce::Slider adsrFilterReleaseSlider;
    
    // Unique ptr in order to keep references also when GUI is destroyed
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsrFilterAttackSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsrFilterDecaySliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsrFilterSustainSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> adsrFilterReleaseSliderAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ADSRComponent)
};
