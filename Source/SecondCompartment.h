/*
  ==============================================================================

    SecondCompartment.h
    Created: 6 Mar 2022 6:06:47pm
    Author:  Bastow_boii 1
 ==============================================================================
                                Description
 
 Initialises the default functions and variables in the class.
  Overrides any Pure Virtual Functions.
  ==============================================================================
*/
//                              References
//                           (DrBrusin, 2022)
//                            (Kengo, S., 2021)
///                            (JUCE, Unknown)

#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "GainSliderLookAndFeel.h"


class BastowGainSlider : public juce::Slider
{
public:
    
    BastowGainSlider()
    {
        setLookAndFeel(&lf);
        setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
        setPopupDisplayEnabled(true, false, this);
        setTextValueSuffix(" dB");
        setVelocityBasedMode (true);
        setVelocityModeParameters (0.15, 1, 0.5, false);
        setSliderStyle(SliderStyle::LinearHorizontal);
    }
    
    ~BastowGainSlider()
    {
        // You have to do this because otherwise the lf will be deleted twice!
        setLookAndFeel(nullptr);
    }
    
    void setColour(juce::Colour colourToSet)
    {
        lf.setSliderColour(colourToSet);
    }
    
    
private:
    GainSliderLookAndFeel lf;
};


class SecondCompartment : public juce::Component,  public juce::Slider::Listener
{
public:
    SecondCompartment(BastowSynthAudioProcessor& p);
    ~SecondCompartment() override;
    
    void paint (juce::Graphics&) override;
    void resized() override;
    
private:
    
    //==============================================================================
                                //Private Functions & variables
    //==============================================================================
    void sliderValueChanged(juce::Slider* slider) override;
    
    BastowSynthAudioProcessor& audioProcessor;

    BastowGainSlider gain1,
    gain2,
    gain3,
    gain4,
    gain5,
    gain6,
    gain7,
    gain8;
    
 
    
    constexpr static int numGainSliders = 8;
    std::array<BastowGainSlider* const, numGainSliders> sliderArray;
    float level = 0.0f;
    
    //==============================================================================
                                //APVTS Slider Connection .h
    //==============================================================================
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> gain1Val;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> gain2Val;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> gain3Val;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> gain4Val;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> gain5Val;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> gain6Val;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> gain7Val;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> gain8Val;
  
    //==============================================================================
                                //RGBA Colours
    //=============================================================================
 
    juce::Colour red = juce::Colour::fromFloatRGBA (0.91f, 0.25f, 0.25f, 1.0f);
    juce::Colour orange = juce::Colour::fromFloatRGBA (0.91f, 0.62f, 0.25f, 1.0f);
    juce::Colour yellow = juce::Colour::fromFloatRGBA (0.91f, 0.84f, 0.25f, 1.0f);
    juce::Colour brightGreen = juce::Colour::fromFloatRGBA (0.74f, 0.91f, 0.25f, 1.0f);
    juce::Colour limeGreen = juce::Colour::fromFloatRGBA (0.31f, 0.91f, 0.25f, 1.0f);
    juce::Colour brightBlue = juce::Colour::fromFloatRGBA (0.25f, 0.66f, 0.91f, 1.0f);
    juce::Colour blue = juce::Colour::fromFloatRGBA (0.25f, 0.42f, 0.91f, 1.0f);
    juce::Colour violet = juce::Colour::fromFloatRGBA (0.62f, 0.25f, 0.91f, 1.0f);
    juce::Colour magenta = juce::Colour::fromFloatRGBA (0.91f, 0.25f, 0.80f, 1.0f);
    juce::Colour offWhite = juce::Colour::fromFloatRGBA (0.83f, 0.83f, 0.89f, 1.0f);
    juce::Colour grey = juce::Colour::fromFloatRGBA (0.42f, 0.42f, 0.42f, 1.0f);
    juce::Colour blackGrey = juce::Colour::fromFloatRGBA (0.2f, 0.2f, 0.2f, 1.0f);
    juce::Colour black = juce::Colour::fromFloatRGBA (0.01f, 0.01f, 0.01f, 1.0f);
    
    //………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SecondCompartment)
};
