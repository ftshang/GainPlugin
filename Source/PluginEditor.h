/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class GainTutorialPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    GainTutorialPluginAudioProcessorEditor (GainTutorialPluginAudioProcessor&);
    ~GainTutorialPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider gainSlider; 

    GainTutorialPluginAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainTutorialPluginAudioProcessorEditor)
};
