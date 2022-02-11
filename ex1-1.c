// SAVING INVESTMENT SIMULATION                       //

// PERINC : increment rate of savings, 5%             //
// PERINT : increment rate of savings, 5% compounded  //
// YEAR   : current year of simulation                //
// SALARY : annual  salary                            //

// PROGRAM  EX1-1				      //

#include<stdio.h>
#include<math.h>
#define perinc   0.05
#define perint   0.05

void main()
{
      int  year;
      double salary,saving;
      FILE *output;
      output=fopen("c:\\work\\ex1-1.out","wt");

      fprintf(output,"SALARY INCREASE RATE  IS    %4.2f \n",perinc);
      fprintf(output,"INTEREST RATE ON SAVINGS    %4.2f \n\n",perint);

	  salary=12000000.0;
	  saving=0.0;
	  year=0;

      fprintf(output,"YEAR         SALARY            SAVINGS \n\n");
      fprintf(output," %2d       %10.0f        %10.0f \n",year,salary,saving);

	  while (year < 30)
	     {
	       ++year;
	       saving = saving + perint * saving + 0.10 * salary;
	       salary = salary + perinc * salary;
	       fprintf(output," %2d       %10.0f        %10.0f \n", year, salary, saving);
	     }
      fclose(output);
}
