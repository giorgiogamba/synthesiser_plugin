/*
  ==============================================================================

    ADSRComponent.cpp
    Created: 15 Nov 2024 6:18:14pm
    Author:  Giorgio Gamba

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ADSRComponent.h"

//==============================================================================
ADSRComponent::ADSRComponent(juce::AudioProcessorValueTreeState& apvts)
{
    adsrFilterAttackSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "ATTACK", adsrFilterAttackSlider);
    adsrFilterDecaySliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "DECAY", adsrFilterDecaySlider);
    adsrFilterSustainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "SUSTAIN", adsrFilterSustainSlider);
    adsrFilterReleaseSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "RELEASE", adsrFilterReleaseSlider);
    
    adsrFilterAttackSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    adsrFilterAttackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    addAndMakeVisible(adsrFilterAttackSlider);
    
    adsrFilterDecaySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    adsrFilterDecaySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    addAndMakeVisible(adsrFilterDecaySlider);
    
    adsrFilterSustainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    adsrFilterSustainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    addAndMakeVisible(adsrFilterSustainSlider);
    
    adsrFilterReleaseSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    adsrFilterReleaseSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    addAndMakeVisible(adsrFilterReleaseSlider);
}

ADSRComponent::~ADSRComponent()
{
}

void ADSRComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void ADSRComponent::resized()
{
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = bounds.getHeight();
    const auto sliderStartX = 0;
    const auto sliderStartY = 0;
    
    adsrFilterAttackSlider.setBounds(sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    adsrFilterDecaySlider.setBounds(adsrFilterAttackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    adsrFilterSustainSlider.setBounds(adsrFilterDecaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    adsrFilterReleaseSlider.setBounds(adsrFilterSustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
}
