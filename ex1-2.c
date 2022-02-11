//  BOUNCING BALL SIMULATION                       //

//  NBOUNC : The number of bounces                 //
//  BOUNCE : The current number of bounces         //
//  V      : The initial velocity of the ball      //
//  VYOLD  : The y velocity at the start of tstep  //
//  VYNEW  : The y velocity at the end   of tstep  //

//  PROGRAM  EX1-2				   //

#include<stdio.h>
#include<math.h>

#define pi   3.1415926
#define ay   -9.8

void main()
{
      int  bounce, nbounc, n;
      float v, angle, tstep, x, y, theta, vx, vyold, vynew, t;
      FILE *output;

      output=fopen("c:\\work\\ex1-2.out","wt");
      fprintf(output,"X-CORDINATE          Y-CORDINATE \n\n");

	   v = 10.0;
	   angle = 80.0;
	   nbounc = 3;
	   tstep = 0.10;

	   x = 0.0;
	   y = 0.0;
	   theta = angle * pi / 180;
	   vx = v * cos(theta);
	   vyold = v * sin(theta);

	   bounce = 0;
	   t = 0.0;

      while (bounce < nbounc)
       {
	   t = t + tstep;
	   x = x + vx * tstep;
	   vynew = vyold + ay * tstep;
	   y = y + (vyold + vynew) * tstep / 2.0;
	   vyold = vynew;
	   fprintf(output,"%10.6f           %10.6f \n",x,y);
		if (y < 0.0)
		 {
		   vyold = fabs(0.75*vyold);
		   y = 0.0;
		   ++bounce;
		 }
       }
fclose(output);
}
