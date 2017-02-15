#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "functions.h"

int i;
 
void fillArray( int A[] )
{
	int num;
	for( i = 0 ; i < 1000 ; i++ )
	{
		num = rand() % 1000;
		A[ i ] = num;
	}
}

void printArray( int A[] )
{
	for( i = 0 ; i < 1000 ; i++ )
	{
		printf("|	%d	|\n",A[ i ]);
	}
}

void bubbleSort( int A[] )
{	
	int operaciones = 0;
	bool cambio = true;
	printf("Arreglo desordenado:\n");
	printArray( A );
	while( cambio )
	{
		cambio = false;
		for( i = 0 ; i < 999 ; i++ )
		{
			operaciones++;
			if( A[ i ] > A[ i + 1 ] )
			{
				cambio = true;
				swap( A , i );
				operaciones = operaciones + 4;
			}			
		}
	}
	printf("Arreglo ordenado:\n");
	printArray( A );
	printf("Se realizaron %d operaciones para ordenar el arreglo\n",operaciones);
}

void swap( int A[] , int index )
{
	int aux;
	aux = A[index + 1 ];
	A[ index + 1 ] = A [ index ];
	A[ index ] = aux;
}
