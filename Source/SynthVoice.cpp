/*
  ==============================================================================

    SynthVoice.cpp
    Created: 2 Nov 2024 4:08:20pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#include "SynthVoice.h"

SynthVoice::SynthVoice()
{
    bIsPrepared = false;
}

bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound)
{
    return dynamic_cast<juce::SynthesiserSound*>(sound);
}

void SynthVoice::prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels)
{
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;
    
    osc.prepare(spec);
    gain.prepare(spec);
    
    osc.setFrequency(220.f);
    gain.setGainLinear(0.01f);
    
    adsrFilter.setSampleRate(sampleRate);
    
    adsrFilterParameters.attack = 0.1f;
    adsrFilterParameters.decay = 0.1f;
    adsrFilterParameters.sustain = 1.0f;
    adsrFilterParameters.release = 1.0f;
    adsrFilter.setParameters(adsrFilterParameters);
    
    bIsPrepared = true;
}

void SynthVoice::startNote(int midiNodeNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
    osc.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNodeNumber));
    adsrFilter.noteOn();
}

void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
    adsrFilter.noteOff();
}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{
    
}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{
    
}

void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    if (!bIsPrepared)
    {
        printf("The voice is not prepared to play. Returning");
        return;
    }
    
    juce::dsp::AudioBlock<float> audioBlock(outputBuffer); // outputBuffer's alias
    osc.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
    
    gain.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
    
    adsrFilter.applyEnvelopeToBuffer(outputBuffer, startSample, numSamples);
}
