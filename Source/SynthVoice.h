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
    
    
    
    
};


