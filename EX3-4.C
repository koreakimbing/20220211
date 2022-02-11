// SIMULATION FOR A SINGLE QUEUEING SYSTEM            //
// DISCRETE EVENT SIMULATION                          //

// SEED   : seed for interarrival time                //
// NSEED  : seed for service time                     //
// MARRVT : the mean of interarrival time             //
// MSERVT : the mean of service time                  //
// NUMCUS : the number of customers at the time       //
// TOTQUE : the totals of queue length                //
// TOTARR : the number of customers to be simulated   //
// AVGWT  : the mean of waiting time                  //

// PROGRAM  EX3-4                                     //

#include <stdio.h>
#include <math.h>

int   status, totarr, next, queue, numcus;
float marrvt, mservt, totque, time, tlevnt, e_arr,e_dep, u, tne[3] ;
long  seed, nseed;
FILE *fp, *fopen();

void init();
void random(long *np, float *up);
void expon(long *np, float rmean, float *ep);
void timing();
void depart();
void arrive();
void report();

//  MAIN PROGRAM  //
void main()
{
	     marrvt=1.0;
	     mservt=0.5;
	     totarr=1000;

	fp = fopen("c:\\work\\ex3-4.out", "w");

	init();
//	fprintf(fp," next  TIME     tlevent    QUEUE    totque\n");  //

	while(numcus < totarr)
	      {
		timing();
		if(next == 1) arrive();
		else depart();
 //		fprintf(fp,"%d  %6.2f   %6.2f    %d     %9.2f \n",next,time,tlevnt,queue,totque);   //

	      }

	report();
}


//  INITIALIZE SYSTEM VARIABLES  //
void init()
{
	time = 0.0;
	status = 0;
	queue = 0;
	tlevnt = 0;
	numcus = 0;
	totque = 0;
	seed = 35213;
	nseed=seed;
	expon(&seed,marrvt,&e_arr);
	tne[1] = time * e_arr;
	tne[2] = 1.e+30;
}


//  DETERMINE TIME & NEXT EVENT  //
//  IF  NEXT=1,  ARRIVE  //
//  IF  NEXT=2,  DEPART  //
void timing()
{
	float rmin;

	if(tne[1] <= tne[2])
	      { rmin = tne[1];
		next = 1;
	      }
	else
	      { rmin = tne[2];
		next = 2;
	      }

	if(rmin >= 1.e+29)
	      printf(" EVENT LIST EMPTY \n");
	time=tne[next];
}


//  ARRIVE EVENT ROUTINE  //
void arrive()
{
	expon(&seed, marrvt, &e_arr);
	tne[1]=time+e_arr;
	if(status == 0)
	      {
		numcus = numcus + 1;
		status = 1;
		expon(&nseed, mservt,&e_dep);
		tne[2] = time + e_dep;
	      }
	else
	      {
		totque = totque + queue * (time - tlevnt);
		tlevnt = time;
		queue = queue + 1;
		if(queue > 100)
		    printf("OVERFLOW OF THE QUEUE \n");
	      }
}


//  DEPART EVENT ROUTINE      //
//  STATUS = 0 : SERVER IDLE  //
//  STATUS = 1 : SERVER BUSY  //
void depart()
{
	if(queue <= 0)
	      { status = 0;
		tne[2] = 1.3e+30;
	      }
	else
	      {
		totque = totque + queue * (time - tlevnt);
		tlevnt = time;
		queue = queue - 1;
		numcus = numcus + 1;
		expon(&nseed,mservt,&e_dep);
		tne[2] = time + e_dep;
	      }
}


//  OUTPUT  FORMAT  //
void report()
{
/*	FILE *fp, *fopen();*/
	float avgwt, avgque;

     /*	fp = fopen("c:\\work\\ex3-4.out", "w");*/
	fprintf(fp,"\n \n \n");
	fprintf(fp,"       SIMULATION FOR A QUEUEING SYSTEM \n");
	fprintf(fp,"       SINGLE-SERVER QUEUEING SYSTEM\n");
	fprintf(fp,"\n \n");
	fprintf(fp," TIME LIMIT : NUMBER OF CUSTOMERS   =  %d \n", totarr);
	fprintf(fp," EXPONENTIAL MEAN INTERARRIVAL TIME =  %3.1f MINUTES \n", marrvt);
	fprintf(fp," EXPONENTIAL MEAN SERVICE TIME      =  %3.1f MINUTES \n", mservt);

	avgwt  = totque / totarr;
	avgque = totque / time;

	fprintf(fp,"\n \n");
	fprintf(fp," MEAN WAITING TIME    =  %9.7f MINUTES \n", avgwt);
	fprintf(fp," MEAN QUEUE LENGTH    =  %9.7f \n\n", avgque);
	fprintf(fp," TOTQUE = %9.7f \n", totque);
	fprintf(fp," TIME   = %9.7f \n",time);
}


//  RANDOM NUMBER GENERATOR  //
void random(long *np, float *up)
{
       *np = *np * 843314861 + 453816693;
       if(*np < 0)
	      { *np = *np +2147483647;
//		*np = *np + 1;                //
	      }
       *up = *np * 0.4656612e-9;
}


//  EXPONETIAL RANDOM VARIABLE GENERATOR  //
void expon(long *np, float rmean, float *ep)
 {
	float u;

	random(np, &u);
	*ep = -(rmean) * log(u);

}
