// SIMULATION FOR A SINGLE QUEUEING SYSTEM : single-pump gas station  //
// TO EVALUATE MEAN QUEUE LENGTH                                      //

// TLIMIT : the time limit expressed in minutes                       //
// TIME   : the time expressed in minutes                             //
// TSTEP  : the time increment in minutes                             //
// TPUMP  : the service time that a custom has left                   //
// PRARR  : the probability of a custom arriving in any minute        //
// U      : uniform random number [0,1)                               //
// TOTQUE : the totals of queue length                                //
// AVEQUE : the average queue length                                  //

// PROGRAM  EX3.0 BASIC PROBLEM  - TEXT 97                                                     //

#include<stdio.h>
#include<math.h>
#define SEED 35213;


long p;
float mean = 4, b;


//  RANDOM NUMBER GENERATOR  //
void random(long *np, float *up)
{
       *np = *np * 843314861 + 453816693;
       if(*np < 0)
	      { *np = *np +2147483647;
		*np = *np + 1;
	      }
       *up = *np * 0.4656612e-9;
}


//  POISSN RANDOM VARIABLE GENERATOR  //
void poissn(long *np, int *pp)
{
       float prod,b,u;

       *pp = 0;
       b = exp(-mean);
       prod = 1;
       random(np,&u);
       prod=prod*u;

       while (prod >= b)
	     { random(np,&u);
	       prod = prod * u;
	       ++(*pp);
	     }
}


 //  MAIN  PROGRAM  //
void main()
{
       long seed,nseed;
       int  p, queue = 0, totque = 0, time=0, totarr=0, arrive, tstep = 1;
       float prarr=1.0/3.0, tpump=0.0, tlimit=100, u=0, aveque=0;
       FILE *output;

	   seed=SEED;
	   nseed=SEED;
	   output=fopen("c:\\work\\ex3-0.out","wt");

       fprintf(output,"       SIMULATION FOR A QUEUEING SYSTEM \n\n");
       fprintf(output,"THE TIME STEP            =  %d \n",tstep);
       fprintf(output,"THE TIME LIMIT           =  %3.0f \n",tlimit);
       fprintf(output,"THE ARRIVAL PROBABILITY  =  %4.2f \n",prarr);
       fprintf(output,"THE POISSON MEAN         =  %1.0f \n",mean);
       fprintf(output,"THE SEED                 =  %ld \n\n",seed);
       fprintf(output,"   TIME      ARRIVAL      QUEUE        TPUMP\n");

       while (time < tlimit)
	     {
	       time = time + tstep;
	       arrive = 0;

	       random(&seed, &u);

	       if (u < (prarr*tstep))
		      { arrive = 1;
			queue = queue + arrive;
			totarr = totarr + 1;
		      }
	       if (tpump > 0.0)
		      { tpump = tpump - tstep;
			    if (tpump < 0.0) tpump = 0.0;
		      }
	       if ((tpump == 0) && (queue != 0))
		      { queue = queue - 1;
			poissn(&nseed,&p);
			tpump = p;
		      }
	       totque = totque + queue;
	       fprintf(output,"   %3d          %d          %2d           %2.0f \n",time,arrive,queue,tpump);
	     }
       aveque = totque / (tlimit/tstep);
       fprintf(output,"  MEAN QUEUE LENGTH  =  %4.2f \n",aveque);
       fprintf(output,"  THE TOTAL ARRIVALS =  %d \n",totarr);
       fprintf(output,"  THE TOTAL QUEUE =  %d \n",totque);
       fclose(output);
}
