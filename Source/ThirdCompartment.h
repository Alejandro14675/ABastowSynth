/*
  ==============================================================================

    ThirdCompartments.h
    Created: 6 Mar 2022 6:07:14pm
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
#include "Oscillator1.h"
#include "Oscillator2.h"
#include "Oscillator3.h"
#include "Oscillator4.h"
#include "Oscillator5.h"
#include "Oscillator6.h"
#include "Oscillator7.h"
#include "Oscillator8.h"
#include "Oscillator9.h"
#include "ADSRSliderLookAndFeel.h"
#include "PluginProcessor.h"


class BastowADSRSlider : public juce::Slider
{
public:
    
    BastowADSRSlider()
    {
        setLookAndFeel(&lf);
        setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
        setPopupDisplayEnabled(true, false, this);
        setTextValueSuffix(" dB");
        setVelocityBasedMode (true);
        setVelocityModeParameters (0.15, 1, 0.5, false);
        setSliderStyle(SliderStyle::RotaryVerticalDrag);
    }
    
    ~BastowADSRSlider()
    {
        // You have to do this because otherwise the lf will be deleted twice!
        setLookAndFeel(nullptr);
    }
    
    void setColour(juce::Colour colourToSet)
    {
        lf.setSliderColour(colourToSet);
    }
    
    void mouseDown (const juce::MouseEvent& event)
    {
        juce::Slider::mouseDown (event);

        setMouseCursor (juce::MouseCursor::NoCursor);
    }

    void mouseUp (const juce::MouseEvent& event)
    {
        juce::Slider::mouseUp (event);

        juce::Desktop::getInstance().getMainMouseSource().setScreenPosition (event.source.getLastMouseDownPosition());

        setMouseCursor (juce::MouseCursor::NormalCursor);
    }

    
private:
   ADSRSliderLookAndFeel lf;
};


class ThirdCompartment : public juce::Component,  public juce::Slider::Listener
{
public:
    ThirdCompartment(BastowSynthAudioProcessor& p );
    ~ThirdCompartment() override;
    
    void paint (juce::Graphics&) override;
    void resized() override;
    
private:
    //==============================================================================
                                //Private Functions & variables
    //==============================================================================
    void sliderValueChanged(juce::Slider* slider) override;
    
    BastowSynthAudioProcessor& audioProcessor;
    
    BastowADSRSlider attackSlider,
    releaseSlider,
    decaySlider,
    sustainSlider;
    
 
    
    constexpr static int numADSRSliders = 4;
    std::array<BastowADSRSlider* const, numADSRSliders> sliderArray;
    float level = 0.0f;
    //==============================================================================
                                //APVTS Slider Connection .h
    //==============================================================================
    
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> attackVal;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> decayVal;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> sustainVal;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> releaseVal;
    
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
  
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ThirdCompartment)
};
