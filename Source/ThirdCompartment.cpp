/*
  ==============================================================================

    ThirdCompartments.cpp
    Created: 6 Mar 2022 6:07:14pm
    Author:  Bastow_boii 1
 ==============================================================================
                                Description

 Using Juce functions this makes the components visible, sets settings for indivisual sliders,
 connects audio to the sliders and sets position within the components boundaries.
 
 ThirdCompartment has to initialise the plugin processor,
 in order to connect the sliders with the set settings in the parameter layout.
  =============================================================================
*/
//                              References
//                           (DrBrusin, 2022)
//                            (Kengo, S., 2021)
///                            (JUCE, Unknown)


#include <JuceHeader.h>
#include "ThirdCompartment.h"

ThirdCompartment::ThirdCompartment(BastowSynthAudioProcessor& p) :
audioProcessor(p), sliderArray{&attackSlider,
    &releaseSlider,
    &decaySlider,
    &sustainSlider
    }
{
    {
        // Some helper functions
        static const auto getFreqSliderColour = [this](int index) {
            static const std::vector<juce::Colour> colours = {yellow, magenta, limeGreen, blue};
            return colours[index];
        };
        
        using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
        static const auto createSliderAttachment = [](juce::AudioProcessorValueTreeState& tree, std::unique_ptr<SliderAttachment>& attachment, juce::String paramID, juce::Slider& slider) {
            attachment = std::make_unique<SliderAttachment>(tree, paramID, slider);
        };
    
        setAlwaysOnTop(true);
        
        // Setup each slider with their colours etc.
        int index = 0;
        for(auto* slider : sliderArray)
        {
            addAndMakeVisible(slider);
            slider->addListener(this);
            slider->setColour(getFreqSliderColour(index++));
        }
        
        // You could also put this in the above for loop at some point, which would be tidy :)
        auto& apvts = audioProcessor.tree;
        createSliderAttachment(apvts, attackVal, attackId, attackSlider);
        createSliderAttachment(apvts, decayVal, decayId, decaySlider);
        createSliderAttachment(apvts, releaseVal, releaseId, releaseSlider);
        createSliderAttachment(apvts, sustainVal, sustainId, sustainSlider);
       
    }
}
    
    //==============================================================================
                                //Making Visible
    //==============================================================================
    
  
    
    //==============================================================================
                                //APVTS Slider Connection
    //==============================================================================

    


ThirdCompartment::~ThirdCompartment()
{
}

void ThirdCompartment::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::transparentWhite);
     //g.fillAll (juce::Colours::white);
}
void ThirdCompartment::resized()
{
 
    auto a = getLocalBounds().withWidth (95.5f).withHeight(95.5f).withY(162.5f);
attackSlider.setBounds (a.withX (172.5f));
    auto b = getLocalBounds().withWidth (95.5f).withHeight(95.5f).withY(162.5f);
decaySlider.setBounds (b.withX (305));
    auto c = getLocalBounds().withWidth (95.5f).withHeight(95.5f).withY(162.5f);
sustainSlider.setBounds (c.withX (440));
    auto d = getLocalBounds().withWidth (95.5f).withHeight(95.5f).withY(162.5f);
releaseSlider.setBounds (d.withX (575));
    

  
  
}
void ThirdCompartment::sliderValueChanged(juce::Slider* slider)
{
}

