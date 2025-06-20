//$Id: GmatPluginFunctions.hpp 35 2012-10-08 16:30:01Z djcinsb $
//------------------------------------------------------------------------------
//                            GmatPluginFunctions
//------------------------------------------------------------------------------
// GMAT: General Mission Analysis Tool
//
// Copyright (c) 2012 Thinking Systems, Inc.
// Free usage granted to all users; this is shell code.  Adapt and enjoy.  
// Attribution is appreciated.
//
// Author: Darrel J. Conway, Thinking Systems, Inc.
// Created: July 15, 2012
//
/**
 * Definition for library code interfaces.
 */
//------------------------------------------------------------------------------
#ifndef GmatPluginFunctions_hpp
#define GmatPluginFunctions_hpp

#include "SampleDefs.hpp"
#include "Factory.hpp"

class MessageReceiver;

extern "C"
{
   Integer    SAMPLE_API GetFactoryCount();
   Factory    SAMPLE_API *GetFactoryPointer(Integer index);
   void       SAMPLE_API SetMessageReceiver(MessageReceiver* mr);
};


#endif /*GmatPluginFunctions_hpp*/
