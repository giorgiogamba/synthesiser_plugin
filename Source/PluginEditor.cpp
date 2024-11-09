// Copyright Giorgio Gamba, 2024

#include "PluginProcessor.h"
#include "PluginEditor.h"

Synthesiser_pluginAudioProcessorEditor::Synthesiser_pluginAudioProcessorEditor (Synthesiser_pluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
    
    adsrFilterAttackSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAudioProcessorValueTreeState(), "ATTACK", adsrFilterAttackSlider);
    adsrFilterDecaySliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAudioProcessorValueTreeState(), "DECAY", adsrFilterDecaySlider);
    adsrFilterSustainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAudioProcessorValueTreeState(), "SUSTAIN", adsrFilterSustainSlider);
    adsrFilterReleaseSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getAudioProcessorValueTreeState(), "RELEASE", adsrFilterReleaseSlider);
    
    oscillatorWaveformsComboBoxAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getAudioProcessorValueTreeState(), "OSC", oscillatorWaveformsComboBox);
    
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

Synthesiser_pluginAudioProcessorEditor::~Synthesiser_pluginAudioProcessorEditor()
{
}

void Synthesiser_pluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void Synthesiser_pluginAudioProcessorEditor::resized()
{
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = bounds.getHeight() / 4 - padding;
    const auto sliderStartX = 0;
    const auto sliderStartY = bounds.getHeight() / 2 - (sliderHeight / 2);
    
    adsrFilterAttackSlider.setBounds(sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    adsrFilterDecaySlider.setBounds(adsrFilterAttackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    adsrFilterSustainSlider.setBounds(adsrFilterDecaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    adsrFilterReleaseSlider.setBounds(adsrFilterSustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
}
