// SIMULATION FOR A QUEUEING SYSTEM                               //
// TO EVALUATE MEAN QUEUE LENGTH                                  //
// -- EACH CAR HAS NORMAL DISTRIBUTION TANK --                    //

// TLIMIT   : the time limit expressed in minutes                 //
// TIME     : the time expressed in minutes                       //
// TSTEP    : the time increment in minutes                       //
// TPUMP    : the service time that a custom has left             //
// PRARR    : the probability of a custom arriving in any minute  //
// MEAN     : the mean of normal distribution                     //
// STDEV    : the standard deviation of normal distribution       //
// AVEQUE   : the average queue length                            //
// TOTQUE   : the totals of queue length                          //
// TOTARR   : the totals of arrivals                              //

// PROGRAM  EX3-2                                                 //

#include<stdio.h>
#include<math.h>
#define SEED 35213;


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


//  NORMAL RANDOM VARIABLE GENERATOR  //
void normal(long *np, float mean, float std, float *lp)
{
       int i=0;
       float sum=0,u;

       while ( i < 12 )
	    {
	      random(np,&u);
	      sum = sum + u;
	      ++i;
	    }
       *lp = mean + (sum - 6.0) * std;
}


//  MAIN  PROGRAM  //
void main()
{
       long seed,nseed;
       int   queue=0, totque=0, totarr=0, arrive, tstep=1;
       float nmean=20,stdev=3;
       float liters, prarr=1.0/4.0, tpump=0.0, time=0.0, tlimit=100, u=0, aveque=0;
       FILE *output;

	   seed=SEED;
	   nseed=SEED;
	   output=fopen("c:\\work\\ex3-2.out","wt");

       fprintf(output,"        SIMULATION FOR A QUEUEING SYSTEM \n\n");
       fprintf(output,"THE TIME STEP                  =  %d \n",tstep);
       fprintf(output,"THE TIME LIMIT                 =  %3.0f \n",tlimit);
       fprintf(output,"THE ARRIVAL PROBABILITY        =  %4.2f \n",prarr);
       fprintf(output,"THE NORMAL MEAN                =  %2.0f \n",nmean);
       fprintf(output,"THE NORMAL STANDARD DEVIATION  =  %1.0f \n",stdev);
       fprintf(output,"THE SEED                       =  %ld \n",seed);
       fprintf(output," TIME    ARRIVE      QUEUE       TPUMP    LITERS\n");

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
		      normal(&nseed,nmean,stdev,&liters);
		      tpump = 1.0 + 1.0 / 8.0 * liters;
		    }
	      totque = totque + queue;
	      fprintf(output," %3.0f      %d       %2d      %10.7f     %5.2f\n",time,arrive,queue,tpump,liters);
	    }
       aveque = totque / (tlimit/tstep);
       fprintf(output,"  MEAN QUEUE LENGTH  =  %4.2f \n",aveque);
       fprintf(output,"  THE TOTAL ARRIVALS =  %d \n",totarr);
       fprintf(output,"  THE TOTAL QUEUE =  %d \n",totque);
       fclose(output);
}
