/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
// Constructor
GainTutorialPluginAudioProcessorEditor::GainTutorialPluginAudioProcessorEditor (GainTutorialPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    gainSlider.setRange(-60.0f, 0.0f, 0.01f);
    gainSlider.setValue(-20.0f);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);

    setSize (200, 300);
}

GainTutorialPluginAudioProcessorEditor::~GainTutorialPluginAudioProcessorEditor()
{
}

//==============================================================================
void GainTutorialPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void GainTutorialPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);

}

void GainTutorialPluginAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &gainSlider)
    {
        audioProcessor.gain = gainSlider.getValue();
    }
}