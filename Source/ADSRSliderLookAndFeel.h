/*
  ==============================================================================

    ADSRSliderLookAndFeel.h
    Created: 15 May 2022 1:20:47am
    Author:  Bastow_boii 1

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
class ADSRSliderLookAndFeel : public juce::LookAndFeel_V4
{
public:
    ADSRSliderLookAndFeel();
    ~ADSRSliderLookAndFeel();
        
    juce::Slider::SliderLayout getSliderLayout (juce::Slider& slider) override;
            
    void drawRotarySlider (juce::Graphics&, int x, int y, int width, int height,
                           float sliderPosProportional, float rotaryStartAngle,
                           float rotaryEndAngle, juce::Slider&) override;
    
    void setSliderColour(juce::Colour colourToUse)
    {
        mainSliderColour = colourToUse;
    }
    
    
private:
    //==============================================================================
                                       //Colours
    //==============================================================================
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

    juce::Colour mainSliderColour = orange;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ADSRSliderLookAndFeel);
};

