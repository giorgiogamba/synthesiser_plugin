/*
  ==============================================================================

    SynthVoice.cpp
    Created: 2 Nov 2024 4:08:20pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#include "SynthVoice.h"

bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound)
{
    return dynamic_cast<juce::SynthesiserSound*>(sound);
}

void SynthVoice::startNote(int midiNodeNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
    
}

void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
    
}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{
    
}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{
    
}

void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    
}
