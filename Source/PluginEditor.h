/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/ADSRComponent.h"

//==============================================================================
/**
*/
class Synthesiser_pluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Synthesiser_pluginAudioProcessorEditor (Synthesiser_pluginAudioProcessor&);
    ~Synthesiser_pluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    juce::ComboBox oscillatorWaveformsComboBox;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscillatorWaveformsComboBoxAttachment;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Synthesiser_pluginAudioProcessor& audioProcessor;
    
    ADSRComponent adsrComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Synthesiser_pluginAudioProcessorEditor)
};
