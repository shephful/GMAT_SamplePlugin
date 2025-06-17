//$Id: ConsolePrint.cpp 36 2012-10-08 23:48:34Z djcinsb $
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
 * Implementation of the command used to write data to the message window or
 * console
 */
//------------------------------------------------------------------------------


#include "ConsolePrint.hpp"
#include "MessageInterface.hpp"
#include "CommandException.hpp"
#include "StringVar.hpp"
#include "Variable.hpp"
#include <sstream>


//#define DEBUG_PARSING
//#define DEBUG_EXECUTION


//------------------------------------------------------------------------------
// ConsolePrint()
//------------------------------------------------------------------------------
/**
 * Default constructor
 */
//------------------------------------------------------------------------------
ConsolePrint::ConsolePrint() :
   GmatCommand          ("ConsolePrint")
{
}


//------------------------------------------------------------------------------
// ~ConsolePrint()
//------------------------------------------------------------------------------
/**
 * Destructor
 */
//------------------------------------------------------------------------------
ConsolePrint::~ConsolePrint()
{
}


//------------------------------------------------------------------------------
// ConsolePrint(const ConsolePrint& cp)
//------------------------------------------------------------------------------
/**
 * Copy constructor
 *
 * @param cp The command copied to this one
 */
//------------------------------------------------------------------------------
ConsolePrint::ConsolePrint(const ConsolePrint & cp) :
   GmatCommand          (cp)
{
}


//------------------------------------------------------------------------------
// ConsolePrint& operator=(const ConsolePrint &cp)
//------------------------------------------------------------------------------
/**
 * Assignment operator
 *
 * @param cp The command copied to this one
 *
 * @return this instance set to match cp
 */
//------------------------------------------------------------------------------
ConsolePrint & ConsolePrint::operator=(const ConsolePrint &cp)
{
   if (this != &cp)
   {
      GmatCommand::operator=(cp);
   }
   
   return *this;
}


//------------------------------------------------------------------------------
// GmatBase *Clone() const
//------------------------------------------------------------------------------
/**
 * Generates a copy of this ConsolePrint command
 */
//------------------------------------------------------------------------------
GmatBase *ConsolePrint::Clone() const
{
   return new ConsolePrint(*this);
}


//// This method is used when objects are renamed in the GUI.  Provide an 
//// implementation if you need it; it's omitted here to keep the code simple
//
//bool ConsolePrint::RenameRefObject(const Gmat::ObjectType type,
//      const std::string & oldName, const std::string & newName)
//{
//   bool retval = false;
//
//   return retval;
//}


//------------------------------------------------------------------------------
//  bool InterpretAction()
//------------------------------------------------------------------------------
/**
 * Parses the command string.
 *
 * @return true if an action was taken, false otherwise.
 */
//------------------------------------------------------------------------------
bool ConsolePrint::InterpretAction()
{
   StringArray chunks = InterpretPreface();
   objectNames.clear();
   parameterNames.clear();

   #ifdef DEBUG_PARSING
      MessageInterface::ShowMessage("Preface chunks as\n");
      for (StringArray::iterator i = chunks.begin(); i != chunks.end(); ++i)
         MessageInterface::ShowMessage("   \"%s\"\n", i->c_str());
      MessageInterface::ShowMessage("\n");
   #endif

   // chunks[0] == "ConsolePrint"; remainder in chunks[1]
   if (chunks.size() > 1)
   {
	   StringArray blocks = parser.SeparateSpaces(chunks[1]);

	   for (UnsignedInt i = 0; i < blocks.size(); ++i)
	   {
		  BuildReferences(blocks[i]);
	   }
   }
   
   return true;
}


//------------------------------------------------------------------------------
// bool Initialize()
//------------------------------------------------------------------------------
/**
 * Prepares the command for use
 *
 * @return true if initialization succeeds, false if not
 */
//------------------------------------------------------------------------------
bool ConsolePrint::Initialize()
{
   theObjects.clear();
   theParameterIds.clear();

   bool retval = false;

   if (GmatCommand::Initialize())
   {
      for (UnsignedInt i = 0; i < objectNames.size(); ++i)
      {
         GmatBase *theObject = FindObject(objectNames[i]);
         if (theObject == NULL)
            throw CommandException("ConsolePrint command cannot find the "
                  "object named \"" + objectNames[i] + "\"");

         // Default id to -1; if set that way, there is no parameter identifier
         Integer id = -1;
         if (parameterNames[i] != "")
         {
            try
            {
               id = theObject->GetParameterID(parameterNames[i]);
            }
            catch (BaseException &)
            {
               // -2 is used to indicate that the ID was not found
               id = -2;
            }
         }

         theObjects.push_back(theObject);
         theParameterIds.push_back(id);
      }

      retval = true;
   }

   return retval;
}


//------------------------------------------------------------------------------
// bool Execute()
//------------------------------------------------------------------------------
/**
 * Runs the command
 *
 * This is where the work of the command is performed.
 *
 * @return true if the command executes, false if it fails
 */
//------------------------------------------------------------------------------
bool ConsolePrint::Execute()
{
   std::string messageString;

   for (UnsignedInt i = 0; i < theObjects.size(); ++i)
   {
      std::string s = GetData(i);
      messageString = messageString + s + "   ";
   }

   MessageInterface::ShowMessage("%s\n", messageString.c_str());
   return true;
}


//------------------------------------------------------------------------------
// void RunComplete()
//------------------------------------------------------------------------------
/**
 * Executes when the mission finished running in the Sandbox, so the command can
 * clean up anything that needs to be cleaned up.
 */
//------------------------------------------------------------------------------
void ConsolePrint::RunComplete()
{
}


//------------------------------------------------------------------------------
// void BuildReferences(const std::string forString)
//------------------------------------------------------------------------------
/**
 * Sets up the object names during parsing
 *
 * @param forString The string that needs to be parsed
 */
//------------------------------------------------------------------------------
void ConsolePrint::BuildReferences(const std::string forString)
{
   StringArray parts = parser.SeparateDots(forString);
   if (parts.size() > 2)
      throw CommandException("Multidot strings are not yet handled; look "
            "at string \"" + forString + "\"");

   if (parts.size() == 0)
      return;

   if (parts[0] == "")
      return;

   objectNames.push_back(parts[0]);
   if (parts.size() == 2)
      parameterNames.push_back(parts[1]);
   else
      parameterNames.push_back("");
}


//------------------------------------------------------------------------------
// std::string GetData(Integer atIndex)
//------------------------------------------------------------------------------
/**
 * Retrieves the data that is written during execution
 *
 * @param atIndex The index pf the data source
 * 
 * @return The string that should be written
 */
//------------------------------------------------------------------------------
std::string ConsolePrint::GetData(Integer atIndex)
{
   std::string retval = "Type not yet handled";

   if (theParameterIds[atIndex] < 0)
   {
      // Handle strings, variables, etc
      if (theObjects[atIndex]->GetTypeName() == "String")
         retval = ((StringVar*)theObjects[atIndex])->ToString();

      if (theObjects[atIndex]->IsOfType("Variable"))
      {
         std::stringstream str;
         Real rv = ((Variable*)theObjects[atIndex])->GetReal();
         str.precision(16);
         str << rv;
         retval = str.str();
      }
   }
   else
   {
      Integer type = theObjects[atIndex]->
            GetParameterType(theParameterIds[atIndex]);

      switch (type)
      {
      case Gmat::STRING_TYPE:
         retval = theObjects[atIndex]->
                        GetStringParameter(theParameterIds[atIndex]);
         break;

      case Gmat::REAL_TYPE:
         {
            std::stringstream str;
            str.precision(16);
            Real rv = theObjects[atIndex]->
                  GetRealParameter(theParameterIds[atIndex]);
            str << rv;
            retval = str.str();
         }
         break;

      case Gmat::INTEGER_TYPE:
         {
            std::stringstream str;
            Real rv = theObjects[atIndex]->
                  GetIntegerParameter(theParameterIds[atIndex]);
            str << rv;
            retval = str.str();
         }
         break;

      default:
         break;
      }
   }

   return retval;
}
