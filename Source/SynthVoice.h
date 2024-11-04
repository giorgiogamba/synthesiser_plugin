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

class SynthVoice : public juce::SynthesiserVoice
{
    
public:
    
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    
    void startNote(int midiNodeNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void pitchWheelMoved(int newPitchWheelValue) override;

    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;
    
private:
    
    juce::dsp::Oscillator<float> osc {[](float x){ return std::sin(x); }};
    
    // Kinds of wave equations. Replace them inside the lambda function to generate different sounds
    // Sinewave: std::sin(x);
    // Sawwave: x / MathConstants<float>::pi;
    // Square wave: x < 0.f ? -1.f : 1.f;
    
    juce::dsp::Gain<float> gain;
    
    bool bIsPrepared;
    
    
};


