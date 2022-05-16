/*
  ==============================================================================

    SecondCompartment.cpp
    Created: 6 Mar 2022 6:06:47pm
    Author:  Bastow_boii 1
 ==============================================================================
                                Description

 Using Juce functions this makes the components visible, sets settings for indivisual sliders,
 connects audio to the sliders and sets position within the components boundaries.
 
 SecondCompartment has to initialise the plugin processor,
 in order to connect the sliders with the set settings in the parameter layout.
  ==============================================================================
*/
//                              References
//                           (DrBrusin, 2022)
//                            (Kengo, S., 2021)
///                            (JUCE, Unknown)


#include <JuceHeader.h>
#include "SecondCompartment.h"

SecondCompartment::SecondCompartment(BastowSynthAudioProcessor& p) :
audioProcessor(p), sliderArray{&gain1,
    &gain2,
    &gain3,
    &gain4,
    &gain5,
    &gain6,
    &gain7,
    &gain8
    }
{
    
    {
        // Some helper functions
        static const auto getFreqSliderColour = [this](int index) {
            static const std::vector<juce::Colour> colours = {red, orange, yellow, brightGreen, limeGreen, brightBlue, blue, violet, grey};
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
        createSliderAttachment(apvts, gain1Val, gain1Id, gain1);
        createSliderAttachment(apvts, gain2Val, gain2Id, gain2);
        createSliderAttachment(apvts, gain3Val, gain3Id, gain3);
        createSliderAttachment(apvts, gain4Val, gain4Id, gain4);
        createSliderAttachment(apvts, gain5Val, gain5Id, gain5);
        createSliderAttachment(apvts, gain6Val, gain6Id, gain6);
        createSliderAttachment(apvts, gain7Val, gain7Id, gain7);
        createSliderAttachment(apvts, gain8Val, gain8Id, gain8);
}
}
    //=============================================================================
                                //Making Visible
    //==============================================================================
    

  
    //==============================================================================
                                //Gain Sliders
    //==============================================================================

   
/*gain1.setLookAndFeel (&gain1LAF);
    gain1.addListener(this);
    gain1.setTextValueSuffix("dB");
    gain1.setPopupDisplayEnabled(true, false, this);
    gain1.setVelocityBasedMode (true);
   
    gain2.setLookAndFeel (&gain2LAF);
    gain2.setVelocityBasedMode (true);
    gain2.addListener(this);
    gain2.setTextValueSuffix("dB");
    gain2.setPopupDisplayEnabled(true, false, this);
    
    gain3.setLookAndFeel (&gain3LAF);
    gain3.setVelocityBasedMode (true);
    gain3.addListener(this);
    gain3.setTextValueSuffix("dB");
    gain3.setPopupDisplayEnabled(true, false, this);
    
    gain4.setLookAndFeel (&gain4LAF);
    gain4.setVelocityBasedMode (true);
    gain4.addListener(this);
    gain4.setTextValueSuffix("dB ");
    gain4.setPopupDisplayEnabled(true, false, this);
    
    gain5.setLookAndFeel (&gain5LAF);
    gain5.setVelocityBasedMode (true);
    gain5.addListener(this);
    gain5.setTextValueSuffix("dB");
    gain5.setPopupDisplayEnabled(true, false, this);

    gain6.setLookAndFeel (&gain6LAF);
    gain6.setVelocityBasedMode (true);
    gain6.addListener(this);
    gain6.setTextValueSuffix("dB");
    gain6.setPopupDisplayEnabled(true, false, this);
    
    gain7.setLookAndFeel (&gain7LAF);
    gain7.setVelocityBasedMode (true);
    gain7.addListener(this);
    gain7.setTextValueSuffix("dB");
    gain7.setPopupDisplayEnabled(true, false, this);
    
    gain8.setLookAndFeel (&gain8LAF);
    gain8.setVelocityBasedMode (true);
    gain8.addListener(this);
    gain8.setTextValueSuffix("dB");
    gain8.setPopupDisplayEnabled(true, false, this);

 */
    //==============================================================================
                                //APVTS Slider Connection
    //==============================================================================
    




SecondCompartment::~SecondCompartment()
{
}

void SecondCompartment::paint (juce::Graphics& g)
{
     g.fillAll (juce::Colours::transparentWhite);
    //g.fillAll (offWhite.brighter(0.2f));
}
void SecondCompartment::resized()
{
    
    juce::Rectangle<int> bounds = getLocalBounds();
    
    juce::FlexBox flexbox;
    
    flexbox.flexDirection = juce::FlexBox::Direction::column;
    flexbox.flexWrap = juce::FlexBox::Wrap::wrap;
    flexbox.alignContent = juce::FlexBox::AlignContent::center;

    flexbox.justifyContent = juce::FlexBox::JustifyContent::flexStart;
    
    juce::Array<juce::FlexItem> itemArray;
    itemArray.add(juce::FlexItem(80, 30, gain1));
    itemArray.add(juce::FlexItem(80, 30,  gain2));
    itemArray.add(juce::FlexItem(80, 30,  gain3));
    itemArray.add(juce::FlexItem(80, 30,  gain4));
    itemArray.add(juce::FlexItem(80, 29,  gain5));
    itemArray.add(juce::FlexItem(80, 30,  gain6));
    itemArray.add(juce::FlexItem(80, 30,  gain7));
    itemArray.add(juce::FlexItem(80, 28.5f,  gain8));
 
    flexbox.items = itemArray;
    flexbox.performLayout(bounds);
    
 
}
void SecondCompartment::sliderValueChanged(juce::Slider* slider)
{
 
   
}
