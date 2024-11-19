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
    
    void setFrequencyModulationParams(const float frequency, const float amplitude);
    
private:
    
    juce::dsp::Oscillator<float> osc {[](float x){ return std::sin(x); }};
    
    juce::dsp::Oscillator<float> fmOsc {[](float x){ return std::sin(x); }};
    
    float fmMod{0.f};
    float fmAmp{0.f};
    int lastMidiNote;
    
    
};
