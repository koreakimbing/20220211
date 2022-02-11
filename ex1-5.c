// ROLLING A DIE SIMULATION                           //

// NROLLS : total number of rolls                     //
// COUNT  : occurrences of each side                  //
// SEED   : seed for random number generator          //
// U      : uniform random number [0,1)               //

// PROGRAM  EX1-5                                     //

#include<stdio.h>
#include<math.h>

#define nrolls   3000
#define SEED    35213


//  RANDOM NUMBER GENERATOR //
void random(long *pn,float *pu)
{
	*pn = *pn * 843314861 + 453816693;
	if(*pn < 0)
	       { *pn = *pn +2147483647;
		 *pn = *pn + 1;
	       }
	*pu = *pn * 0.4656612e-9;
	return;
}


//  MAIN  PROGRAM  //
void main()
{
       int count[6], side, i;
       long n=SEED;
       float u=0;
       FILE *output;
       output = fopen("c:\\work\\ex1-5.out","wt");

       for (i = 0; i < 6; ++i)   count[i]=0;
       i=0;
	    while (i < nrolls)
	    {
		random(&n,&u);
		side = floor(u * 6) ;
		count[side] = count[side] + 1;
		++i;
	    }
       fprintf(output,"         THE STATISTICS\n\n");
	    for (i = 0 ; i<6 ;++i)
		fprintf(output,"SIDE   %d  OCCURED    %d    TIMES\n",i+1,count[i]);
       fclose(output);
}
