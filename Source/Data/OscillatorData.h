/*
  ==============================================================================

    OscillatorData.h
    Created: 16 Nov 2024 4:59:24pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class OscillatorData : public juce::dsp::Oscillator<float>
{
public:
    
    void prepareToPlay(juce::dsp::ProcessSpec& spec);
    
    void getNextAudioBlock(juce::dsp::AudioBlock<float>& block);
    
    void setWavetype(const int selectedTypeIdx);
    
    void setWaveFrequency(const int midiNoteNumber);
    
private:
    
    juce::dsp::Oscillator<float> osc {[](float x){ return std::sin(x); }};
    
};
