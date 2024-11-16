/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

#include "UI/ADSRComponent.h"
#include "UI/OscillatorComponent.h"

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
       
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Synthesiser_pluginAudioProcessor& audioProcessor;
    
    OscillatorComponent oscillatorComponent;
    
    ADSRComponent adsrComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Synthesiser_pluginAudioProcessorEditor)
};
