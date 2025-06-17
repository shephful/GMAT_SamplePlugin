//$Id: SampleFactory.hpp 35 2012-10-08 16:30:01Z djcinsb $
//------------------------------------------------------------------------------
//                          AvroInterfaceFactory
//------------------------------------------------------------------------------
// GMAT: General Mission Analysis Tool.
//
// Copyright (c) 2012 Thinking Systems, Inc.
// Free usage granted to all users; this is shell code.  Adapt and enjoy.  
// Attribution is appreciated.
//
// Author: Darrel J. Conway, Thinking Systems, Inc.
// Created: September 20, 2012
//
//
/**
 * Definition of the factory used to create message writing commands in this
 * plugin
 */
//------------------------------------------------------------------------------


#ifndef SampleFactory_hpp
#define SampleFactory_hpp

#include "SampleDefs.hpp"
#include "Factory.hpp"


/**
 * Factory class that creates one class of your plugin's objects
 *
 * Rename this class from SampleFactory to something more descriptive of your 
 * plugin object(s).
 *
 * @note: The "SAMPLE_API" descriptor needs to match the definition in your 
 * ...Defs.hpp file
 */
class SAMPLE_API SampleFactory : public Factory
{
public:
   SampleFactory();
   virtual ~SampleFactory();
   SampleFactory(const SampleFactory& elf);
   SampleFactory& operator=(const SampleFactory& elf);

   // Implement one and only one of the following per Factory:
   //virtual SpaceObject*     CreateSpacecraft(const std::string &ofType,
   //                                          const std::string &withName = "");
   //virtual SpacePoint*      CreateSpacePoint(const std::string &ofType,
   //                                          const std::string &withName = "");        
   //virtual Propagator*      CreatePropagator(const std::string &ofType,
   //                                          const std::string &withName = "");
   //virtual ODEModel*        CreateODEModel(const std::string &ofType,
   //                                          const std::string &withName = "");
   //virtual PhysicalModel*   CreatePhysicalModel(const std::string &ofType,
   //                                             const std::string &withName = "");
   //virtual PropSetup*       CreatePropSetup(const std::string &ofType,
   //                                         const std::string &withName = "");
   //virtual Parameter*       CreateParameter(const std::string &ofType,
   //                                         const std::string &withName = "");
   //virtual Burn*            CreateBurn(const std::string &ofType,
   //                                    const std::string &withName = "");
   //virtual StopCondition*   CreateStopCondition(const std::string &ofType,
   //                                             const std::string &withName = "");
   //virtual CalculatedPoint* CreateCalculatedPoint(const std::string &ofType,
   //                                               const std::string &withName = "");
   //virtual CelestialBody*   CreateCelestialBody(const std::string &ofType,
   //                                             const std::string &withName = "");
   //virtual SolarSystem*     CreateSolarSystem(const std::string &ofType,
   //                                           const std::string &withName = "");
   //virtual Solver*          CreateSolver(const std::string &ofType,
   //                                      const std::string &withName = ""); 
   //virtual Subscriber*      CreateSubscriber(const std::string &ofType,
   //                                          const std::string &withName = "",
   //                                          const std::string &fileName = "");
   //virtual EphemerisFile*   CreateEphemerisFile(const std::string &ofType,
   //                                             const std::string &withName = "");
   //virtual GmatCommand*     CreateCommand(const std::string &ofType,
   //                                       const std::string &withName = "");
   //virtual AtmosphereModel* CreateAtmosphereModel(const std::string &ofType,
   //                                               const std::string &withName = "",
   //                                               const std::string &forBody = "Earth");
   //virtual Function*        CreateFunction(const std::string &ofType,
   //                                        const std::string &withName = "");
   //virtual Hardware*        CreateHardware(const std::string &ofType,
   //                                        const std::string &withName = "");
   //virtual AxisSystem*      CreateAxisSystem(const std::string &ofType,
   //                                          const std::string &withName = "");
   //virtual CoordinateSystem* CreateCoordinateSystem(const std::string &ofType,
   //                                                 const std::string &withName = "");
   //virtual MathNode*        CreateMathNode(const std::string &ofType,
   //                                        const std::string &withName = "");
   //virtual Attitude*        CreateAttitude(const std::string &ofType,
   //                                        const std::string &withName = "");
   //virtual MeasurementModel*
   //                         CreateMeasurementModel(const std::string &ofType,
   //                                        const std::string &withName = "");
   //virtual CoreMeasurement* CreateMeasurement(const std::string &ofType,
   //                                        const std::string &withName = "");
   //virtual DataFile*        CreateDataFile(const std::string &ofType,
   //                                        const std::string &withName = "");
   //virtual ObType*          CreateObType(const std::string &ofType,
   //                                      const std::string &withName = "");
   //virtual TrackingSystem*  CreateTrackingSystem(const std::string &ofType,
   //                                        const std::string &withName = "");
   //virtual TrackingData*    CreateTrackingData(const std::string &ofType,
   //                                        const std::string &withName = "");
   //virtual Event*           CreateEvent(const std::string &ofType,
   //                                     const std::string &withName = "");
   //virtual EventLocator*    CreateEventLocator(const std::string &ofType,
   //                                     const std::string &withName = "");
   //virtual Interface*       CreateInterface(const std::string &ofType,
   //                                         const std::string &withName = "");
};

#endif /* SampleFactory_hpp */
