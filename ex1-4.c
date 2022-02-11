// SAVING  SIMULATION WITH RANDOM VARIABLES                     //

// PERINC : increment of salary,  uniform random number         //
// PERINT : increment of savings, 9% compounded                 //
// YEAR   : current year of simulation                          //
// PERLOW : lower bound  0%                                     //
// PERHIG : upper bound 10%                                     //
// SEED   : seed for the random number generator                //
// U      : uniform random number [0,1)                         //

// PROGRAM  EX1-4                                               //

#include<stdio.h>
#include<math.h>

#define perint   0.09
#define SEED     35213


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


//  MAIN  PROGRAM  //
void main()
{
      int  year;
      long n=SEED;
      float salary,saving,perinc,u=0,perlow=0, perhig=10;
      FILE *output;
      output=fopen("c:\\work\\ex1-4.out","wt");

	   salary=12000000.0;
	   saving=0.0;
	   perinc=0;
	   year=0;

      fprintf(output,"SALARY INCREASE RATE IS     %3.1f - %4.1f \n",perlow,perhig);
      fprintf(output,"INTEREST RATE ON SAVINGS    %4.2f \n",perint);
      fprintf(output,"\nYEAR  SALARY.INC.RATE    SALARY            SAVING\n");
      fprintf(output," %2d        %4.2f       %10.0f        %10.0f\n",year,perinc,salary,saving);
      while (year < 30)
	 {
	     ++year;
	     saving = saving + perint * saving + 0.10 * salary;
	     random(&n,&u);
	     perinc = (int)(u * (perhig+1-perlow) + perlow);
	     perinc = perinc * 0.01;
	     salary = salary + perinc * salary;
	     fprintf(output," %2d        %4.2f       %10.0f        %10.0f\n",year,perinc,salary,saving);
	 }
      fclose(output);
}


