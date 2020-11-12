//////////////////////////////////////////////////////////////
// Fichier 		: libRobotPekee.h
// Projet  		: OXYGEN
// Description:	: RDDC linkable Pekee
// Date	 Création	: LR : 01/04/2003
// Modification		: 
//
// (C) Copyright Wany SA 1999-2001
// This work contains confidential trade secrets of Wany SA.
// Use, examination, copying, transfer and disclosure to others
// are prohibited, except with the express written agreement of Wany SA.
//
// Auteurs: Laurent Ricatti.
// 	     
////////////////////////////////////////////////////////////////////

#ifndef __LIBROBOTPEKEE_H
#define __LIBROBOTPEKEE_H

#ifndef __LIBROBOT_H
#include "libRobot.h"
#endif

#ifndef __VIRTUALDEVICELED_H
#include "VirtualDeviceLED.h"
#endif

#ifndef __VIRTUALDEVICESERIAL_H
#include "VirtualDeviceSERIAL.h"
#endif

#ifndef __VIRTUALDEVICEIR_H
#include "VirtualDeviceIR.h"
#endif

#ifndef __VIRTUALDEVICEMOTOR_H
#include "VirtualDeviceMOTOR.h"
#endif

#ifndef __VIRTUALDEVICEOPP_H
#include "VirtualDeviceOPP.h"
#endif

#ifndef __VIRTUALDEVICEIMPACT_H
#include "VirtualDeviceImpact.h"
#endif

#ifndef __VIRTUALDEVICETEMPERATURE_H
#include "VirtualDeviceTemperature.h"
#endif

#ifndef __VIRTUALDEVICELIGHT_H
#include "VirtualDeviceLight.h"
#endif

#ifndef __VIRTUALDEVICEBUZZER_H
#include "VirtualDeviceBuzzer.h"
#endif

#ifndef __VIRTUALDEVICEACCU_H
#include "VirtualDeviceAccu.h"
#endif

#ifndef __VIRTUALDEVICEHALBIOS_H
#include "VirtualDeviceHALBios.h"
#endif

#ifndef __LIBDRIVERLEDMESSAGES_H
#include "libDriverLEDMessages.h"
#endif

#ifndef __LIBDRIVERIRMESSAGES_H
#include "libDriverIRMessages.h"
#endif

#ifndef __LIBDRIVERMOTORMESSAGES_H
#include "libDriverMOTORMessages.h"
#endif

#ifndef __LIBDRIVERBUZZERMESSAGES_H
#include "libDriverBuzzerMessages.h"
#endif

#ifndef __LIBDRIVERACCUMESSAGES_H
#include "libDriverAccuMessages.h"
#endif

#ifndef __LIBDRIVERTEMPERATUREMESSAGES_H
#include "libDriverTemperatureMessages.h"
#endif


#ifndef __LIBDRIVERLIGHTMESSAGES_H
#include "libDriverLIGHTMessages.h"
#endif

#ifndef __LIBDRIVERIMPACTMESSAGES_H
#include "libDriverIMPACTMessages.h"
#endif

#ifndef __DIRECTOPPDIALOG_H
#include "DirectOppDialog.h"
#endif

/* Summary
   Uses RDDC synchronous protocol. Each user demand is sent to
   robot and WRobotPekee waits robot response to return.       */
#define LIBROBOTPEKEE_MODE_SYNCHRONOUS	0
/* Summary
   Uses PekeeV1 opp function key FK_GET_MEASURE to force robot
   to notify internal states every 100 ms. Before execute user
   deman using synchronous RDDC protocol, WRobotPekee try to use
   values automaticaly sent by the robot.
   
   
   
   If the stored values are too old, WRobotPekee is using RDDC
   synchronous protocol. In this case, each user demand is sent
   to robot and WRobotPekee waits robot response to return.      */
#define LIBROBOTPEKEE_MODE_FAST			1
/* Summary
   Uses PekeeV1 opp function key FK_GET_MEASURE to force robot
   to notify internal states every 50ms . Before execute user
   deman using synchronous RDDC protocol, WRobotPekee try to use
   values automaticaly sent by the robot.
   
   
   
   If the stored values are too old, WRobotPekee is using RDDC
   synchronous protocol. In this case, each user demand is sent
   to robot and WRobotPekee waits robot response to return.      */
#define LIBROBOTPEKEE_MODE_VERYFAST		2


#define MEASURESTIMEOUT	51

#define PEKEEV1_NB_IRSENSORS	15

/* Summary
   This is the base Pekee robot object.
   
   
   
   See Also
   See the <LINK Hight level programs, tutorial> for more
   details on how to create a <B>libRobotPekee</B> project.
   
   <LINK Example 1> and <LINK Example 2>
   
   
   
   Requirements
   <B>Header</B>: Declared in libRobotPekee.h
   
   <B>Library</B>: Use libRobotPekee.lib                    */
class WRobotPekee:public WRobot
{
private:
	WDriver	*pDriverLED;
	WDriver	*pDriverIR;
	WDriver	*pDriverMOTL;
	WDriver	*pDriverMOTR;
	WDriver	*pDriverBUZZER;
	WDriver *pDriverSERIALCOM1;
	WDriver *pDriverACCUCPU;
	WDriver *pDriverACCUEXT0;
	WDevice *pDeviceHALBios;
	WDriver *pDriverLIGHT;
	WDriver *pDriverInternalTEMPERATURE;
	WDriver *pDriverExternalTEMPERATURE;
	WDriver *pDriverIMPACT;

	BOOL bConnected;

	WDriver *ObtainDriver(char *pseDriverName);

	DWORD dwStatupMode;
	ROBOTINTERNALSTATES PekeeOPPInternalStates;
	DWORD dwPekeeOPPInternalStatesTime;
			

	virtual void OnNewSpecificNetworkMessage(DWORD dwMessage,DWORD dwMessageSize,void *pMessage);
	void ApplyStartupMode(void);

public:
	 /* Summary
	    It's the default WRobotPekee constructor. Choose the
	    communication system to use.
	    
	    
	    
	    Parameters
	    dwMode :  Communication mode to use. See <LINK Communication modes>
	              constants
	    
	    Note
	        * Default value is LIBROBOTPEKEE_MODE_FAST.
	        * If another constant than LIBROBOTPEKEE_MODE_SYNCHRONOUS
	          is used, WRobotPekee send OPP frame FK_GET_MEASURES with
	          FK_MEASURE_TYPE_INTERNALSTATES subtype value to force robot
	          to automaticaly send its internal state values. Of course,
	          robot microcontroler program must respond to this OPP
	          function key ( you can use microcontroler program
	          RemoteDriversCalls for exemple).
	                                                                        */
	 WRobotPekee				( DWORD dwMode=LIBROBOTPEKEE_MODE_FAST);
	virtual ~WRobotPekee		( );


	/* Summary
	   Call this method to obtain the product version that runs the
	   microcontroler program.
	   
	   Returns
	   If no error, the returned value is a string that explains the
	   robot product version.
	   
	   If error, the returned value is "?".
	   
	   
	   
	   Note
	   This method make a remote halbios device call.
	   
	   
	   
	   See Also
	   GetHALVersion.                                                */
	virtual WString GetRobotVersion(void);
	/* Summary
	   Call this method to obtain the HAL version of the running
	   microcontroler program.
	   
	   Returns
	   If no error, the returned value is a string that explains the
	   hal version.
	   
	   If error, the returned value is "?".
	   
	   
	   
	   Note
	   This method make a remote halbios device call.
	   
	   
	   
	   See Also
	   GetRobotVersion.                                              */
	virtual WString GetHALVersion(void);

	/* Summary
	   The <B>Connect</B> method establishes a TCP connection to a
	   real or simulated robot. This is the fisrt method you have to
	   call when using the <B>WRobotPekee</B> object.
	   
	   
	   
	   When the program is running on the robot's embedded PC card,
	   you have to <B>Connect </B>to "localhost".
	   
	   
	   
	   The <B>Connect</B> method always connects to:
	   
	       * <I>PekeeOnNetwork.exe</I> when connecting to a real
	         robot,
	       * <I>Plugin dynamic loader</I> when connecting to a
	         simulated robot.
	   
	   Parameters
	   pszHostName :         [in] IP address or network name to connect to.
	   pszChooseRobotName :  [in] Robot name for a simulated robot in RSL, set
	                         to NULL if robot is a real robot.
	   dwTCPPort :           [in] Remote TCP port. If server is using default
	                         port set dwTCPPort to 0.
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	       * In this case, WRobotPekee ask robot for devices names
	         and drivers names and call the PrintDevices and PrintDrivers
	         method.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Remarks
	       * When connecting to RSL, if pszChooseRobotName is NULL
	         \or "" then WRobot object connects to the first found robot.
	       * If already connected to a robot, <B>Connect</B> method
	         first disconnect from the robot and then connect.
	   
	   
	   
	   Example
	   This example shows a basic connection:
	   <CODE>
	   WRobotPekee pekee;
	   
	   <COLOR Blue>void</COLOR> main(<COLOR Blue>void</COLOR>)
	   {
	   <COLOR Blue>if</COLOR>(pekee.Connect("10.1.108.243") <COLOR Color 1>//Pekee embedded PC card IP address with PekeeOnNetwork.exe running</COLOR>
	       {
	       wuint16 IRMeasures[20];
	       pekee.GetIRMeasures(IRMeasures,<COLOR Blue>sizeof</COLOR>(IRMeasures));
	     <COLOR Color 1>  //display values</COLOR>
	       }
	   }
	   </CODE>
	   
	   
	   This example shows a basic connection to a simulated robot in
	   multi-robots environment in RSL:
	   <CODE>
	   WRobotPekee pekee;
	   
	   <COLOR Blue>void</COLOR> main(<COLOR Blue>void</COLOR>)
	   {
	   <COLOR Blue>if</COLOR>(pekee.Connect("10.1.108.242","Pekee4") <COLOR Color 1>//IP address where RSL is running</COLOR>
	       {
	       wuint16 IRMeasures[20];
	       pekee.GetIRMeasures(IRMeasures,<COLOR Blue>sizeof</COLOR>(IRMeasures));
	     <COLOR Color 1>  //display values</COLOR>
	       }
	   }
	   </CODE>
	   See Also
	   <LINK Example 1, Example>                                                                                                                       */
	virtual BOOL Connect		( char *pszHostName,char *pszChooseRobotName=NULL,DWORD dwTCPPort=0);

	/* Summary
	   The <B>Connect</B> method establishes a TCP connection to a
	   real or simulated robot. This is the first method you have to
	   call when using the <B>WRobotPekee</B> object.
	   
	   
	   
	   The <B>Connect</B> method always connects to:
	   
	       * <I>PekeeOnNetwork.exe</I> when connecting to a real
	         robot
	       * <I>Plugin dynamic loader</I> when connecting to a
	         simulated robot
	   
	   Returns
	   If the function succeeds, the return value is non-zero.
	   
	       * In this case, WRobotPekee asks the robot for device
	         names and driver names and calls the PrintDevices and
	         PrintDrivers methods.
	   
	   If the function fails, the return value is zero.
	   
	   Description
	   There are two ways for this function to connect to the
	   desired robot:
	   
	         1. The function first checks whether there are
	            \arguments in the command line. If these arguments specify a
	            server and a robot name, the function connects to them. (See <LINK Command line options>)
	         2. If no valid arguments are found in the command line,
	            the function opens a dialog box that displays all the robots
	            \on the network. The user has to choose a robot in this
	            dialog box, and the function connects to this robot.
	   
	   Note
	   If no valid arguments are found in the command line, the
	   function opens a dialog box that uses a Robot Manager Service
	   to build a list of the robots on the network. If no Robot
	   Manager Service is running on the network, the dialog box
	   will be empty.
	   
	   Remarks
	       * If already connected to a robot, the <B>Connect</B>
	         method first disconnects from the robot and then reconnects.
	   
	   
	   
	   Example
	   This example shows a basic connection:
	   <CODE>
	   WRobotPekee pekee;
	   
	   <COLOR Blue>void</COLOR> main(<COLOR Blue>void</COLOR>)
	   {
	   <COLOR Blue>if</COLOR>(pekee.Connect() <COLOR Color 1>//Open a dialog box that lists all Pekees with PekeeOnNetwork.exe running</COLOR>
	       {
	       wuint16 IRMeasures[20];
	       pekee.GetIRMeasures(IRMeasures,<COLOR Blue>sizeof</COLOR>(IRMeasures));
	     <COLOR Color 1>  //display values</COLOR>
	       }
	   }
	   </CODE>
	   
	   
	   You can also use the command line to specify connection
	   \parameters. The Connect function of the preceding example
	   will use the command line parameters and will not open a
	   dialog box if you run your program this way :
	   <CODE>
	   MyProgram.exe /server localhost /robot Pekee2
	   </CODE>
	   See Also
	   <LINK Example 1.1>,<LINK Command line options>                                                                                          */
	virtual BOOL Connect(void);

	/* Summary
	   Call this method to disconnect from a robot.
	   
	   
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.       */
	virtual BOOL Disconnect	( );

	/* Summary
	   Call this method to make the Pekee LED light on.
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Note
	   This method make a remote <B>led0</B> driver call.     */
	BOOL	LedOn				( void);
	/* Summary
	   Call this method to make the Pekee LED light off.
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Note
	   This method make a remote <B>led0</B> driver call.     */
	BOOL	LedOff				( void);

	/* Summary
	   Call this method to obtain the external light level (in Lux).
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   
	   
	   Parameters
	   wLightLevel :  [out] Current light level in Lux
	   
	   
	   Note
	   This method make a remote <B>light0</B> driver call.          */
	BOOL	GetLight			(wuint16 &wLightLevel);

	/* Summary
	   Call this method to make the Pekee emit a beep.
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Note
	   This method make a remote <B>buzz0</B> driver call.    */
	BOOL	Beep				( void);

	/* Summary
	   Call this method to make the Pekee emit a sound .
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Note
	   This method make a remote <B>buzz0</B> driver call.    */
	BOOL	SetSound			( wuint16 frequency);

	/* Summary
	   Call this method to set the Pekee base speed.
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Parameters
	   iSpeed :     [in] Translation speed in mm/s
	   iSteering :  [in] Rotation speed in degree/s
	   Note
	       * It's better to use <B>SetSpeed</B> instead of <B>SetMotorsSpeed</B>
	         because this method make only on remote device call (to <B>halbios</B>
	         device). Using <B>SetMotorsSpeed</B>, two remote drivers
	         calls are made to <B>mot0</B> and <B>mot1</B> drivers.
	       * This method make a remote <B>halbios</B> device call.                  */
	BOOL	SetSpeed			( wint16 iSpeed,wint16 iSteering);
	/* Summary
	   Call this method to get the Pekee base speed.
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Parameters
	   iSpeed :     [in] Translation speed in mm/s
	   iSteering :  [in] Rotation speed in degree/s
	   Note
	       * It's better to use <B>GetSpeed</B> instead of <B>GetMotorsSpeed</B>
	         because this method make only on remote device call (to <B>halbios</B>
	         device). Using <B>GetMotorsSpeed</B>, two remote driver calls
	         are made to <B>mot0</B> and <B>mot1</B> drivers.
	       * This method make a remote <B>halbios</B> device call.                  */
	BOOL	GetSpeed			( wint16 &iSpeed,wint16 &iSteering);
	/* Summary
	   Call this method to obtain the left and right odometers
	   count.
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Note
	   This method make a remote <B>mot0</B> and <B>mot1</B> driver
	   call.
	   
	   
	   
	   Parameters
	   uiOdoLeftCount :   [out] Left Odometer count (0 to 65535
	                      non\-signed)
	   uiOdoRightCount :  [out] Right Odometer count (0 to 65535
	                      non\-signed)                              */
	BOOL	GetOdometersCount	( wint32& uiOdoLeftCount,wint32& uiOdoRightCount);
	
	/* Summary
	   Call this method to set the Pekee motors speed.
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Note
	       * It's better to use <B>SetSpeed</B> instead of <B>SetMotorsSpeed</B>
	         because this method make only on remote device call (to <B>halbios</B>
	         device). Using <B>SetMotorsSpeed</B>, two remote driver calls
	         are done to <B>mot0</B> and <B>mot1</B> drivers.
	       * This method make a remote <B>mot0</B> and <B>mot1</B>
	         driver calls.
	   
	   Parameters
	   iLeftSpeed :   [in] Left motor speed in mm/s
	   iRightSpeed :  [in] right motor speed in mm/s                                */
	BOOL	SetMotorsSpeed		( wint16 iLeftSpeed,wint16 iRightSpeed);
	/* Summary
	   Call this method to obtain the current motors speed (in
	   mm/s).
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Parameters
	   iLeftSpeed :   [out] Left motor speed in mm/s
	   iRightSpeed :  [out] Right motor speed in mm/s
	   
	   
	   Note
	   This method make a remote <B>mot0</B> and <B>mot1</B> driver
	   call.                                                        */
	BOOL	GetMotorsSpeed		( wint16 &iLeftSpeed,wint16 &iRightSpeed);
	

	/* Summary
	   Call this method to obtain the number of IR sensors.
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Note
	   This method make a remote <B>irg0</B> driver call.     */
	wuint16 GetNbIR				( void);
	/* Summary
	   Call this method to obtain the IR sensors measures.
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   Parameters
	   pIRSensorsMeasures :  [out] wuint16 table to get IR measures
	   iBufferSize :         [in] Table byte size
	   Example
	   * This example shows how to get IR measures using GetIRMeasures on a real Pekee: *
	   
	   <CODE>WRobotPekee pekee;
	   
	   <COLOR Blue>void</COLOR> main(<COLOR Blue>void</COLOR>)
	   {
	   <COLOR Blue>if</COLOR>(pekee.Connect("10.1.108.243")
	       {
	       wuint16 IRMeasures[PEKEEV1_NB_IRSENSORS];
	       pekee.GetIRMeasures(IRMeasures,<COLOR Blue>sizeof</COLOR>(IRMeasures));
	     <COLOR Color 1>  //display values</COLOR>
	       }
	   }
	   </CODE>
	   
	   
	   * This example shows how to get IR measures using GetIRMeasures on a simulated  Pekee with 20 IR sensors: *
	   
	   <CODE>WRobotPekee pekee;
	   
	   <COLOR Blue>void</COLOR> main(<COLOR Blue>void</COLOR>)
	   {
	   <COLOR Blue>if</COLOR>(pekee.Connect("10.1.108.243")
	       {
	       wuint16 IRMeasures[20];
	       pekee.GetIRMeasures(IRMeasures,<COLOR Blue>sizeof</COLOR>(IRMeasures));
	     <COLOR Color 1>  //display values</COLOR>
	       }
	   }
	   </CODE>
	   
	   
	   * This example shows how to get IR measures using GetIRMeasures on a simulated  Pekee with unknow IR sensors: *
	   
	   <CODE>WRobotPekee pekee;
	   
	   <COLOR Blue>void</COLOR> main(<COLOR Blue>void</COLOR>)
	   {
	   <COLOR Blue>if</COLOR>(pekee.Connect("10.1.108.243")
	       {
	       wuint16 iNbSensors=pekee.GetNbIR();
	       wuint16 *pIRMeasures=<COLOR Blue>new</COLOR> wuint16[iNbSensors];
	       pekee.GetIRMeasures(pIRMeasures,<COLOR Blue>sizeof</COLOR>(wuint16)*iNbSensors);
	       <COLOR Color 1>//display values
	   
	       //and then delete allocated memory
	       </COLOR><COLOR Blue>delete</COLOR><COLOR Color 1> </COLOR>[] pIRMeasures
	       }
	   }
	   </CODE>
	   Note
	   This method make a remote <B>irg0</B> driver call.                                                              */
	BOOL	GetIRMeasures		( wuint16 *pIRSensorsMeasures,wuint16 iBufferSize);

	/* Summary
	   Call this method to add external distance information to IR
	   sensor readings.
	   
	   Parameters
	   sensorId :  [in] sensor number
	   value :     [in] distance value in millimeters
	   validity :  [in] validity duration in milliseconds
	   Note
	       * SensorId must be between 0 and GetNbIR() - 1
		   * SensorId higher than 29 are ignored
	       * When GetIRMeasures is called, <I>value</I> is retrieved
	         if it is less than the real sensor reading, otherwise the
	         real reading is unchanged.
	       * After <I>validity</I> milliseconds, the external
	         distance information is automatically deleted. If
	         DRIVERIR_SETMEASURE_ALWAYSVALID is used for this parameter,
	         the value is always valid.
	       * If DRIVERIR_SETMEASURE_REAL is used for <I>value</I>,
	         the previous external value is deleted.
	                                                                     */
	BOOL SetIRMeasure(wuint16 sensorId, wuint16 value, wuint16 validity);

	/* Summary
	   Call this method to obtain the current Pekee position.
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Note
	       * This method makes a remote <B>halbios</B> device call.
	       * When doing very short movements (a few centimeters,
	         stop, then a few more centimeters) the absolute position
	         loses accuracy. You should reset this using <B>ResetPosition</B>.
	       * Because odometers don't have rotation direction,
	         forward-backward sequences add uncertainty.
	   
	   Parameters
	   fX :      [out] X position in meters
	   fY :      [out] Y position in meters
	   fTheta :  [out] Rotation angle [\-2PI,2PI]                              */

	BOOL	GetPosition			( float& fX, float& fY, float& fTheta);
	/* Summary
	   Call this method to set the current Pekee position to a
	   specified value.
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Note
	   This method make a remote <B>halbios</B> device call.
	   
	   
	   
	   Example
	   This is user when doing local moving : set current position
	   to 0,0,0 and then do the move until next position is not
	   complete
	   
	   
	   
	   Parameters
	   fX :      [in] X position in meters
	   fY :      [in] Y position in meters
	   fTheta :  [in] Rotation angle [\-2PI,2PI]                   */
	BOOL	SetPosition			( float  fX, float  fY, float  fTheta);
	/* Summary
	   Call this method to reset the current Pekee position to
	   (0,0,0).
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Note
	   This method makes a remote <B>halbios</B> device call.  */
	BOOL	ResetPosition		( void);

	/* Summary
	   Call this method to make Pekee write to its serial port (<I>it's
	   not your computer port</I>).
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Note
	   This method make a remote <B>com1</B> driver call.
	   
	   
	   
	   Parameters
	   pData :       [in] data buffer to write on the serial port.
	   uiDataSize :  [in] Byte size to write                            */
	BOOL	SerialWrite			( wchar * pData,wuint32 uiDataSize);
	/* Summary
	   Call this method to read Pekee serial port (<I>inot your
	   computer's serial port</I>).
	   
	   Returns
	   If the function succeeds, the return value is the number of
	   chars read.
	   
	   If the function fails, or if there is no chars to read the
	   \return value is zero.
	   
	   
	   
	   Note
	   This method make a remote <B>com1</B> driver call.
	   
	   
	   
	   Parameters
	   pData :       [out] data buffer to write read chars to.
	   uiDataSize :  [in] Byte size to read                        */
	DWORD	SerialRead			( wchar * pData,wuint32 uiDataSize);

	/* Summary
	   Call this method to obtain the internal temperature (in 1/10
	   degrees Celsius).
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Parameters
	   wTemperatureLevel :  [out] Temperature level (in 1/10 degrees
	                        Celsius)
	   
	   
	   Note
	   This method make a remote <B>temp0</B> driver call.           */
	BOOL	GetInternalTemperature	( wint16 &wTemperatureLevel);
	/* Summary
	   Call this method to obtain the external temperature (in 1/10
	   degrees Celsius).
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Parameters
	   wTemperatureLevel :  [out] Temperature level (in 1/10 degrees
	                        Celsius)
	   
	   
	   Note
	   This method make a remote <B>temp1</B> driver call.           */
	BOOL	GetExternalTemperature	( wint16 &wTemperatureLevel);


	/* Summary
	   Call this method to obtain current CPU accumulator remaining
	   capacity [0..100%]
	   
	   
	   
	   Parameters
	   dwCapacity :  [out] Accumulator capacity from 0 to 100 %
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Note
	   This method make a remote <B>accucpu</B> driver call.
	   
	   
	   
	   See Also
	   <LINK Accumulator status, Accumulators status values>        */
	BOOL GetCPUAccuCurrentCapacity	( wuint16& dwCapacity);
	/* Summary
	   Call this method to obtain current motors accumulator
	   remaining capacity [0..100%]
	   
	   
	   
	   Parameters
	   dwCapacity :  [out] Accumulator capacity from 0 to 100 %
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   Note
	   This method make a remote <B>accuext0</B> driver call.
	   
	   
	   
	   See Also
	   <LINK Accumulator status, Accumulators status values>    */
	BOOL GetExt0AccuCurrentCapacity	( wuint16& dwCapacity);
	/* Summary
	   Call this method to obtain current CPU accumulator status
	   (charging mode, power level)
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   Parameters
	   dwStatus :  [out] Accumulator status
	   
	   Note
	   This method make a remote <B>accucpu</B> driver call.
	   
	   
	   
	   See Also
	   <LINK Accumulator status, Accumulators status values>     */
	BOOL GetCPUAccuStatus			( wuint16& dwStatus);
	/* Summary
	   Call this method to obtain current Motors accumulator status
	   (charging mode, power level)
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   Parameters
	   dwStatus :  [out] Accumulator status
	   
	   Note
	   This method make a remote <B>accuext0</B> driver call.
	   
	   
	   
	   See Also
	   <LINK Accumulator status, Accumulators status values>        */
	BOOL GetExt0AccuStatus			( wuint16& dwStatus);


	/* Summary
	   Call this method to obtain the number of impacts that have
	   \occurred since the robot was started.
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, or if no impacts append, the return
	   value is zero.
	   
	   
	   
	   
	   
	   Note
	   This method make a remote <B>imp0</B> driver call.         */
	BOOL GetNbImpacts				(wuint16 &NbImpacts);


	/* Summary
	   Call this method for the embedded PC card to send an OPP
	   frame on the bus.
	   
	   Returns
	   If the function succeeds, the return value is nonzero.
	   
	   If the function fails, the return value is zero.
	   
	   
	   
	   
	   
	   Note
	       * This method sends a Specific Network Message through <LINK WRobot::SendSpecificNetworkMessage@DWORD &@DWORD@void *@DWORD, SendSpecificNetworkMessage>
	         method.
	       * Data size is the number of 16 bits words in the
	         message.
	   
	   Parameters
	   FK :         [in] Function key (see function keys bible)
	   signature :  [in] sender signature
	   wType :      [in] FK frame sub\-type
	   wDataSize :  [in] Size of the message. The size is the number
	                of 16\-bit words in the message
	   pData :      [in] Data to send
	   See Also
	   <LINK Example 2, Example>                                                                                                                                   */
	BOOL PCCARDSendOppFrame(wuint16 FK,wuint16 signature,wuint16 wType,wuint16 wDataSize,wuint16 *pData);
	/* Summary
	   Override this method to be called each time an OPP frame is
	   read from the PC card FIFO.
	   
	   Note
	       * Data size is the number of 16 bits words in the
	         message.
	   
	   
	   
	   Parameters
	   FK :              [in] Function key (see function keys bible)
	   signature :       [in] sender signature
	   wType :           [in] FK frame sub\-type
	   wDataWordsSize :  [in] Size of the message. The size is the number
	                     of 16 bit words in the message
	   pData :           [in] Data to send<P>
	   See Also
	   <LINK Example 2, Example>                                          */
	virtual void PCCARDOnNewOppFrame(wuint16 FK,wuint16 signature,wuint16 wType,wuint16 wDataWordsSize,wuint16 *pData){};
};

#endif