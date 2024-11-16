/*
  ==============================================================================

    SynthVoice.h
    Created: 2 Nov 2024 4:08:20pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "SynthSound.h"
#include "Data/ADSRData.h"
#include "Data/OscillatorData.h"

class SynthVoice : public juce::SynthesiserVoice
{
    
public:
    
    SynthVoice();
    
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    
    void prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels);
    
    void startNote(int midiNodeNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void pitchWheelMoved(int newPitchWheelValue) override;

    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;
    
    void update(const float attack, const float decay, const float sustain, const float release);
    
    OscillatorData& getOscillator() { return oscillator; }
    
private:
    
    OscillatorData oscillator;
    
    juce::dsp::Gain<float> gain;
    
    juce::AudioBuffer<float> synthBuffer;
    
    ADSRData adsrFilter;
    juce::ADSR::Parameters adsrFilterParameters;
    
    bool bIsPrepared;
};
