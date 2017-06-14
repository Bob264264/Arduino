/*****************************************************************************/
//	Function:    Get the accelemeter of the x/y/z axis. 
//  Hardware:    Grove - 3-Axis Digital Accelerometer(±1.5g)
//	Arduino IDE: Arduino-1.0
//	Author:	 Frankie.Chu		
//	Date: 	 Jan 10,2013
//	Version: v0.9b
//	by www.seeedstudio.com
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
/*******************************************************************************/

#include <Wire.h>
#include "MMA7660.h"
MMA7660 accelemeter;

static double oldXVel;
static double oldYVel;
static double oldZVel;
static double oldXPos;
static double oldYPos;
static double oldZPos;

void setup()
{
	accelemeter.init();  
	Serial.begin(9600);
}
void loop()
{
	int8_t x;
	int8_t y;
	int8_t z;
	float ax,ay,az;
  double xAcc = 0;
  double yAcc = 0;
  double zAcc = 0;

  int loops = 10;
  int timeDelay = 50;
  for (int i = 0; i < loops; i++){
    accelemeter.getXYZ(&x,&y,&z);
    xAcc += x-.5;
    yAcc += y+1;
    zAcc += z-21;   //subtracting gravity 
    delay(timeDelay);
  }
  double avgXAcc = (double) xAcc/loops;
  double avgYAcc = (double) yAcc/loops;
  double avgZAcc = (double) zAcc/loops;

  double xVel = oldXVel + (loops*timeDelay)*avgXAcc;
  double yVel = oldYVel + (loops*timeDelay)*avgYAcc;
  double zVel = oldZVel + (loops*timeDelay)*avgZAcc;

  oldXVel = xVel;
  oldYVel = yVel;
  oldZVel = zVel;

  double xPos = oldXPos + (loops*timeDelay)*xVel;
	double yPos = oldYPos + (loops*timeDelay)*yVel;
  double zPos = oldZPos + (loops*timeDelay)*zVel;

  oldXPos = xPos;
  oldYPos = yPos;
  oldZPos = zPos;
 
	Serial.println("Acceleration");
	Serial.print("x = ");
  Serial.println(avgXAcc); 
  Serial.print("y = ");
  Serial.println(avgYAcc);   
  Serial.print("z = ");
  Serial.println(avgZAcc);
  Serial.println("Velocity");
  Serial.print("x = ");
  Serial.println(xVel); 
  Serial.print("y = ");
  Serial.println(yVel);   
  Serial.print("z = ");
  Serial.println(zVel);
  Serial.println("Position");
  Serial.print("x = ");
  Serial.println(xPos/1000000); 
  Serial.print("y = ");
  Serial.println(yPos/1000000);   
  Serial.print("z = ");
  Serial.println(zPos/1000000);
	
	//accelemeter.getAcceleration(&ax,&ay,&az);
  //  Serial.println("accleration of X/Y/Z: ");
	//Serial.print(ax);
	//Serial.println(" g");
	//Serial.print(ay);
	//Serial.println(" g");
	//Serial.print(az);
	//Serial.println(" g");
	Serial.println("*************");
	delay(500);
}


