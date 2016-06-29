# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mpi.h"


int main ( int argc, char *argv[] );
void heat_part ( int n, int p, int id, double x_min, double x_max );

int main ( int argc, char *argv[] )
{
//liczba przedziałów
int n=12;
//liczba procesów potomnych
int j=8
int i=0;
int id;
int p;
double x_max;
double x_min;
double a = 0.0; // lewy brzeg przedzialu
double b = 1.0; // prawy brzeg przedzialu



// wspolrzedna lewego punktu dla wezla id
  x_min = ( ( double )( p * n + 1 - id * n - i ) * a   
          + ( double )(             id * n + i ) * b ) 
          / ( double ) ( p * n + 1              );

  i = n + 1;

  // wspolrzedna prawego punktu dla wezla id
  x_max = ( ( double )( p * n + 1 - id * n - i ) * a   
          + ( double )(             id * n + i ) * b ) 
          / ( double )( p * n + 1              );



MPI_Init (&argc, &argv);
MPI_Comm intercomm;
MPI_Comm_spawn("heat", MPI_ARGV_NULL,j,MPI_INFO_NULL ,0, MPI_COMM_WORLD,&intercomm, MPI_ERRCODES_IGNORE); 

MPI_Send(&x_max, 1,MPI_Double,50,intercomm);
MPI_Send(&x_min, 1,MPI_Double,51,intercomm);
MPI_Send(&n, 1,MPI_INT,52,intercomm);

MPI_Finalize();
}

