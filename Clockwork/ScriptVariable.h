/******************************************************************************
  Author: Matthew Nolan                       Clockwork Crossplatform Framework
    Date: April, 2001                                           [Crossplatform]
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
#ifndef SCRIPTVARIABLE_H
#define SCRIPTVARIABLE_H 1
#include "Script.h"

class ScriptVariable
{
    //** De/constructors **//
    public: ScriptVariable(ScriptDataTypeDef*& hDef, void* hValue = NULL, bool hConst = false);
    public: virtual ~ScriptVariable();

    //** Public Member Functions **//
    public:
    void            Execute();


    //** Runtime Data Members **//
    public:
    ScriptVariable*         mCurrent;   //Current setting of the variable
    APtr<ScriptFunction>    mFunction;  //If the variable is a function 
    SHORT                   mScope;     //0 global to script
    
    STRING                  mName;      //Name of the variable
    SHORT                   mType;      //Value is integer, a STRING, an object, etc..
    ScriptDataTypeDef*      mDef;
    APtr<ScriptDataType>    mValue;     //Ptr to object holding the value
    bool                    mConstant;  //Cant be assigned to and such
};


#endif //ifndef SCRIPTVARIABLE_H


