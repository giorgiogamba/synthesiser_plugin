/*
  ==============================================================================

    ADSRData.cpp
    Created: 15 Nov 2024 6:18:41pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#include "ADSRData.h"

void ADSRData::update(const float attack, const float decay, const float sustain, const float release)
{
    adsrParameters.attack = attack;
    adsrParameters.decay = decay;
    adsrParameters.sustain = sustain;
    adsrParameters.release = release;
}
