/*
  ==============================================================================

    ADSRData.h
    Created: 15 Nov 2024 6:18:41pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class ADSRData : public juce::ADSR
{
public:
    
    void update(const float attack, const float decay, const float sustain, const float release);

    
private:
    
    juce::ADSR::Parameters adsrParameters;
    
    
};

