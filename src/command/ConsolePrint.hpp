//$Id: ConsolePrint.hpp 36 2012-10-08 23:48:34Z djcinsb $
//------------------------------------------------------------------------------
//                            ConsolePrint
//------------------------------------------------------------------------------
// GMAT: General Mission Analysis Tool.
//
// Copyright (c) 2012 Thinking Systems, Inc.
// Usage under the Academic Free License 3.0 granted to all users.
// All Other Rights Reserved.
//
// Author: Darrel J. Conway, Thinking Systems, Inc.
// Created: July 15, 2012
//
/**
 * Definition of the command used to write data to the message window or console
 */
//------------------------------------------------------------------------------

#ifndef ConsolePrint_hpp
#define ConsolePrint_hpp

#include "SampleDefs.hpp"
#include "GmatCommand.hpp"
#include "MessageInterface.hpp"

/**
 * Example command used in the Plugin walkthrough document
 */
class SAMPLE_API ConsolePrint : public GmatCommand
{
public:
   ConsolePrint();
   virtual ~ConsolePrint();
   ConsolePrint(const ConsolePrint& etb);
   ConsolePrint& operator=(const ConsolePrint& etb);

   virtual GmatBase* Clone() const;
   virtual bool InterpretAction();

   //bool ConsolePrint::RenameRefObject(const Gmat::ObjectType type,
   //      const std::string & oldName, const std::string & newName)
   virtual bool Initialize();
   virtual bool Execute();
   virtual void RunComplete();

   DEFAULT_TO_NO_CLONES
   DEFAULT_TO_NO_REFOBJECTS

protected:
   /// Names of the object supplying the data
   StringArray objectNames;
   /// Names of the object parameters
   StringArray parameterNames;
   /// Collection of objects that get written
   ObjectArray theObjects;
   /// Associated object parameter IDs
   std::vector<Integer> theParameterIds;

   void BuildReferences(const std::string forString);
   std::string GetData(Integer atIndex);
};

#endif /* ConsolePrint_hpp */
