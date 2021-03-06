//////////////////////////////////////////////////////////////////////////////////////
// RAID Driver
// Version : 1.01
// Modify : 2010.1.19

#ifndef DRIVER__H
#define DRIVER__H

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
BOOL   Device_Attach(  char * , char * , int , int , int , int , int , int , int , int , int , int );
BOOL   Device_Detach(  char * , char * , int , int , int , int , int , int , int , int , int , int );
//
double Analog_In(   int , int , int , int * );
void   Analog_Out(  int , int , int , double , int * );
//
//
int    Digital_In(  int , int , int , int , int * );
void   Digital_Out( int , int , int , int , int , int * );

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------

#endif
