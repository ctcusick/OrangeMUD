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
#ifndef SAVELOADABLE_H
#define SAVELOADABLE_H 1


#define kAttr_ObjectClass   "ObjectClass"
#define kAttr_VRef          "VRef"



class SaveLoadable
{
    //** De/constructors **//
    public: SaveLoadable();
    public: virtual ~SaveLoadable();

    //** Public Member Functions **//
    public:
    void    LoadValuesFrom(XMLReader& hXML, XMLTag& hTag);
    


    //** Abstract Member Functions **//
    public:
    virtual void    SaveTo(XMLWriter& hFile, const CHAR* hTagName) = 0;
    virtual void    SaveValuesTo(XMLWriter& hFile) = 0;
    virtual bool    MatchValues(XMLReader& hXML, XMLTag& hTag) = 0;
};







#endif //ifndef SAVELOADABLE_H
