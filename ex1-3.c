// RANDOM NUMBER GENERATOR OUTPUT TEST                //

// COUNT  : occur rences of each interval             //
// SEED   : seed for random number generator          //
// U      : uniform random number [0,1)               //
// LIMIT  : total number of random numbers            //

// PROGRAM  EX1-3                                     //

#include<stdio.h>
#include<math.h>

#define LIMIT   5000
#define SEED    9965


void random(long *pn, float *pu);
void freq(float) ;
void report();
void print_p(int, float);
FILE *output,*fopen();
int COUNT[5];
float OUT_P[5];


//  RANDOM NUMBER GENERATOR  //
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


 void print_p(int i, float u)
 {
   int j;
   int k;

       k=(i % 5);
     if( k == 4 )
      {   OUT_P[k]=u;
	for(j=0; j<=4; ++j)
		 fprintf(output,"   %f   ",OUT_P[j]);
	 fprintf(output,"\n");
				 }
     else  OUT_P[k]=u;
     return;
		    }

//   THE  FREQUENCE  TABLE    //
 void freq(float u)
 {float r1=0.0,r2=0.2;
  int i;

  for(i=0; i<5; ++i)
   { if ( r1 <= u && u < r2 )
	COUNT[i]=COUNT[i]+1;
	r1=r1+0.2;
	r2=r2+0.2;
		   }
      return;
    }


//   OUTPUT  FORMAT                        //
void report()
{float r1=0.0,r2=0.2;
 int i;

   fprintf(output,"\n     THE RREQUENCE TABLE\n\n");
   for(i=0; i<5; ++i)
    {
      fprintf(output,"    %4.2f - %4.2f  =  %4d\n",r1,r2,COUNT[i]);
      r1=r1+0.2;
      r2=r2+0.2;
   }
   return;
   }


//  MAIN  PROGRAM                             //
void main()
{
 int i;
 long n=SEED;
 float u=0;
 output = fopen("c:\\work\\ex1-3.out","wt");
fprintf(output,"                 THE RANDOM NUMBER TEST OUTPUT\n\n");
  for (i = 0; i < 5; ++i)   COUNT[i]=0;
  i=0;
  while (i < LIMIT)
   {
     random(&n,&u);
     print_p(i, u);
     freq(u);
       ++i;
	     }

  report();
  fclose(output);
}
