/******************************************************************************
  Author: Matthew Nolan                                      OrangeMUD Codebase
    Date: January 2001                                          [Crossplatform]
 License: MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Copyright 2000-2019 Matthew Nolan, All Rights Reserved
******************************************************************************/
#ifndef OBJECTPOPULATION_H
#define OBJECTPOPULATION_H 1
#include "Population.h"


class ObjectPopulation
    : public Population
//  , public SaveLoadable //Comes from Population
{
    //** De/constructors **//
    public: ObjectPopulation(bool hIsOldObjRepop);
    public: virtual ~ObjectPopulation();
    
    //** SaveLoadable Functions **//
    virtual void    SaveTo(XMLWriter& hFile, const CHAR* hTagName);
    virtual void    SaveValuesTo(XMLWriter& hFile);
    virtual bool    MatchValues(XMLReader& hXML, XMLTag& hTag); 

    //** LoadOld Abstract Functions **//
    virtual bool        MatchValues(MUDFile& hFp, CHAR* hName);
    virtual bool        MatchLists(MUDFile& hFp, CHAR* hName);
    static void         LoadListInto(MUDFile& hFp, OPopulationArray& hList);
    
    
    //** Public Member Functions **//
    public:
    virtual void        Dirty();
    virtual void        RePopulate();
    virtual void        RePopulate(ObjectHolder* hOH);
    virtual void        Convert();              //Outdated


    //** Runtime Data Members **//
    public:
    Object*             mInPlay;

    //** Persistant Data Members **//
    public:
    VREF                mObjectVRef;
    LONG                mObjectFlags;
    BYTE                mContFlags;
    LONG                mLoadMin;
    LONG                mLoadMax;
    BYTE                mChance;
    SHORT               mLiquid;
    SHORT               mToWearLoc;
    OPopulationArray    mPopulationsInside;

    VNUM                mObjectOldVnum;         //Outdated
    VNUM                mObjectRoomValue1Vnum;  //Outdated
    bool                mIsOldObjRepop;         //Outdated
};




#endif //ifndef OBJECTPOPULATION_H
