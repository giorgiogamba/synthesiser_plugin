/*
  ==============================================================================

    SynthSound.h
    Created: 2 Nov 2024 4:08:46pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{

public:
    
    bool appliesToNote(int midiNodeNumber) override { return true; }
    bool appliesToChannel (int midiChannel) override { return true; }
    
};
