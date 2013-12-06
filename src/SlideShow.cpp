//
//  SlideShow.cpp
//  SlideShowApp
//
//  Created by Jason Van Cleave on 4/20/13.
//
//
#include "SlideShow.h"



SlideShow::SlideShow()
{

}

void SlideShow::setup(string photosFolder)
{
    ofDirectory photosDirectory(photosFolder);
    photosDirectory.listDir();
    ofLogVerbose() << photosDirectory.path();
    vector<ofFile> files = photosDirectory.getFiles();
    ofLogVerbose() << "files.size() :" << files.size();
    
    int numFiles = files.size();
    int maxNumFiles = 20;
    for (int i=0; i<files.size(); i++)
    {
        if (images.size()<maxNumFiles)
        {
            ofFile filePath = files[ofRandom(files.size())].path();
            if (filePath.getExtension() == "png")
            {
                ofImage image;
                if(image.loadImage(filePath))
                {
                    image.resize(ofGetWidth(), ofGetHeight());
                    images.push_back(image);
                }
            }
        }
        
        
        
    }
    ofLogVerbose() << "images.size() " << images.size();
    counter = 0;
    currentImage = &images[counter];
    previousImage = NULL;
    waitCounter = 0;

}

void SlideShow::update()
{
    
    if (transitionColor+1<=255)
    {
        transitionColor++;
        
    }else
    {
        if (transitionColor == 255)
        {
            if (waitCounter<300)
            {
                waitCounter++;
                //ofLogVerbose() << "waitcounter";
            }else
            {
                waitCounter=0;
            }
        }
        
        if(waitCounter == 0)
        {
            transitionColor =0;
            if (counter+1 < images.size())
            {
                counter++;
            }else
            {
                counter = 0;
            }
            previousImage = currentImage;
            currentImage = &images[counter];
        }
    }
}

void SlideShow::draw()
{
    ofEnableAlphaBlending();
    if (previousImage != NULL)
    {
        ofSetColor(255, 255, 255, 255-transitionColor);
        previousImage->draw(0, 0);
    }
    ofSetColor(255, 255, 255, transitionColor);
    currentImage->draw(0, 0);
    ofDisableAlphaBlending();
    ofDrawBitmapStringHighlight(ofToString(waitCounter), 20, 20, ofColor::black, ofColor::yellow);
}





