/*
  ==============================================================================

    OscillatorData.cpp
    Created: 16 Nov 2024 4:59:24pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#include "OscillatorData.h"

void OscillatorData::prepareToPlay(juce::dsp::ProcessSpec& spec)
{
    prepare(spec);
}

void OscillatorData::setWavetype(const int selectedTypeIdx)
{
    switch(selectedTypeIdx)
    {
        case 0:
            // Sinewave
            initialise ([](const float x){return std::sin(x); });
            break;
            
        case 1:
            // Sawwave
            initialise ([](const float x){return x / juce::MathConstants<float>::pi; });
            break;
        case 2:
            // Square wave
            initialise ([](const float x){return x < 0.f ? -1.f : 1.f; });
            break;
        default:
            break;
    }
    
    return;
}

void OscillatorData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block)
{
    process(juce::dsp::ProcessContextReplacing<float>(block));
}

void OscillatorData::setWaveFrequency(const int midiNoteNumber)
{
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
}
