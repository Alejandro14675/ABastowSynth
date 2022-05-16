/*
  ==============================================================================

    FourthCompartment.cpp
    Created: 6 Mar 2022 6:07:36pm
    Author:  Bastow_boii 1
 ==============================================================================
                                Description

 Using Juce functions this makes the components visible, sets settings for indivisual sliders,
 connects audio to the sliders and sets position within the components boundaries.
 
 FourthCompartment has to initialise the plugin processor,
 in order to connect the sliders with the set settings in the parameter layout.
  =============================================================================
*/
//                              References
//                           (DrBrusin, 2022)
//                            (Kengo, S., 2021)
///                            (JUCE, Unknown)


#include <JuceHeader.h>

#include "FourthCompartment.h"


FourthCompartment::FourthCompartment(BastowSynthAudioProcessor& p) :
audioProcessor(p), sliderADSRArray{&filterRes,
    &filterCutoff}, sliderFreqArray{&masterVol}
{
    {
        // Some helper functions
        static const auto getADSRSliderColour = [this](int index) {
            static const std::vector<juce::Colour> colours = {black};
            return colours[index];
            
         
            
        };
        {
            // Some helper functions
            static const auto getFreqSliderColour = [this](int index) {
                static const std::vector<juce::Colour> colours = {limeGreen, red};
                return colours[index];
                
           
                
            };
        
        using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
        static const auto createSliderAttachment = [](juce::AudioProcessorValueTreeState& tree, std::unique_ptr<SliderAttachment>& attachment, juce::String paramID, juce::Slider& slider) {
            attachment = std::make_unique<SliderAttachment>(tree, paramID, slider);
        };

        setAlwaysOnTop(true);
        
        // Setup each slider with their colours etc.
        int index = 0;
        for(auto* slider : sliderFreqArray)
        {
            addAndMakeVisible(slider);
            slider->addListener(this);
            slider->setColour(getADSRSliderColour(index++));
        }
        
        // You could also put this in the above for loop at some point, which would be tidy :)
        auto& apvts = audioProcessor.tree;
        createSliderAttachment(apvts, cutoffVal, filterCutoffId, filterCutoff);
        createSliderAttachment(apvts, resVal, filterResId, filterRes);

      
    int index2 = 0;
    for(auto* slider : sliderADSRArray)
    {
        addAndMakeVisible(slider);
        slider->addListener(this);
        slider->setColour(getFreqSliderColour(index2++));
    }
        auto& apvts2 = audioProcessor.tree;
        createSliderAttachment(apvts2, masterVal, gainMasterId, masterVol);
    }

    setAlwaysOnTop(true);
 
  
    //==============================================================================
                                //APVTS Slider Connection
    //==============================================================================
    
    resVal = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, filterResId, filterRes);

    cutoffVal = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, filterCutoffId, filterCutoff);

    masterVal = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, gainMasterId, masterVol);
   
   
}
}
FourthCompartment::~FourthCompartment()
{
}

void FourthCompartment::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::transparentWhite);
    //g.fillAll (juce::Colours::white);
}

void FourthCompartment::resized()
{
 
    auto a = getLocalBounds().withWidth (85).withHeight(85).withX(20);
    filterRes.setBounds (a.withY (50));
    auto b = getLocalBounds().withWidth (85).withHeight(85).withX(20);
filterCutoff.setBounds (b.withY (145));
    auto d = getLocalBounds().withWidth (98.5f).withHeight(125).withX(15);
masterVol.setBounds (d.withY (312.5f));
  
}
void FourthCompartment::sliderValueChanged(juce::Slider* slider)
{
   
}
