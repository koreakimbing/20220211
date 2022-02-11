// MONTE CARLO SIMULATION                      //
// PROGRAM  EX2-1                              //

#include <stdio.h>
#include <math.h>


 FILE *fp, *fopen();

 void random(long *np, float *up);


//  MAIN PROGRAM  //
 void main()
{  long  seed, limit, count, i ;
   float x,y,s,u;

	 seed=9965;
	 limit=50000;
	 count=0;
	 i=1;
	 fp = fopen("c:\\work\\ex2-1.out", "w");

    fprintf(fp," SEED    =   %d  \n", seed);
    while ( i <= limit )
       {
	 random(&seed, &u);
	 x=u;
	 random(&seed, &u);
	 y=u;
	 if ( (x*x + y*y) <= 1.0 )
	      count=count+1;
	 i=i+1;
       }

    s=count/(float)limit;
    s=s*4;

    fprintf(fp," LIMIT   =   %5u \n", limit);
    fprintf(fp," COUNT   =   %5u \n", count);
    fprintf(fp," RESULT  =   %10.8f \n", s);
 };


//  RANDOM NUMBER GENERATOR  //
 void random(long *np, float *up)
{
       *np = *np * 843314861 + 453816693;
       if(*np < 0)
	    {   *np = *np +2147483647;
		*np=*np+1;}
       *up = *np * 0.4656612e-9;
}

