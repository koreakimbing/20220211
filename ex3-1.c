// SIMULATION FOR DOUBLE QUEUEING SYSTEM                        //
// TO EVALUATE MEAN QUEUE LENGTH                                //
// Two server and                                               //
// The service time has poisson distribution.                   //

// TLIMIT   : the time limit expressed in minutes               //
// TIME     : the time expressed in minutes                     //
// TSTEP    : the time increment in minutes                     //
// TPUMP(i) : the service time that a car has left in server i  //
// PRARR    : the probability of a car arriving in any minute   //
// AVEQUE   : the average queue length                          //
// TOTQUE   : the totals of queue length                        //
// TOTARR   : the totals of arrivals                            //

// PROGRAM  EX3-1                                               //

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


//  THE SERVICE TIME HAS POISSON DISTRIBUTION  //
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


//  MAIN PROGRAM  //
void main()
{
       long seed,nseed;
       int  p, queue=0, totque=0, totarr=0, arrive, tstep=1, i;
       float prarr=1.0/3.0, tpump[3], time=0.0, tlimit=100, mean=4, u=0, aveque=0;
       FILE *output;
       output=fopen("c:\\work\\ex3-1.out","wt");

	   seed=SEED;
	   nseed = SEED;
	   tpump[1] = 0;
	   tpump[2] = 0;

       fprintf(output,"        SIMULATION FOR DOUBLE QUEUEING SYSTEM       \n\n");
       fprintf(output,"THE TIME STEP            =  %d \n",tstep);
       fprintf(output,"THE TIME LIMIT           =  %3.0f \n",tlimit);
       fprintf(output,"THE ARRIVAL PROBABILITY  =  %4.2f \n",prarr);
       fprintf(output,"THE POISSON MEAN         =  %1.0f \n",mean);
       fprintf(output,"THE SEED                 =  %ld \n\n",seed);
       fprintf(output,"     TIME     ARRIVAL     QUEUE     TPUMP[1]     TPUMP[2] \n");

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
		 i = 0;
			while ( i < 2 )
			    { i = i + 1;
			      if (tpump[i] > 0)
				    { tpump[i] = tpump[i] - tstep;
			      if (tpump[i] < 0.0) tpump[i] = 0.0;
				    }
			      if ((tpump[i] == 0) && (queue != 0))
				    { queue = queue - 1;
				      poissn(&nseed, &p);
				      tpump[i] = p;
				    }
			    }   //  END OF INNER WHILE  //
		 totque = totque + queue;
		 fprintf(output,"     %3.0f         %d          %d          %2.0f           %2.0f \n"
		 ,time,arrive,queue,tpump[1],tpump[2]);
	       }   //  END OF  OUTER WHILE  //
       aveque = totque / (tlimit/tstep);
       fprintf(output,"  MEAN QUEUE LENGTH  =  %4.2f \n",aveque);
       fprintf(output,"  THE TOTAL ARRIVALS =  %d \n",totarr);
       fprintf(output,"  THE TOTAL QUEUE =  %d \n",totque);
       fclose(output);
}
