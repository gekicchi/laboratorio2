#include <stdio.h>
#include <stdlib.h>
int i;

void NumeroParImpar(int a)
{
	if (a%2 == 1) // impar
	{
		printf("%d es impar\n",a);
		return;
	}
	
	printf("%d es par\n",a);
}


void NumeroPrimo(int a)
{
	for(i=2;i<a;i++)
	{
		if (a%i==0)
		{
			printf("%d no es primo\n",a);
			return; // el numero no es primo
		}
	}
	
	printf("%d es primo\n",a);
	
	return; // el numero es primo
}

float PromedioMinMax(int arr[], int size)
{
	int max=arr[0], min=arr[0];
	float prom = 0;
	
	printf("Numeros: ");
	for (i=0; i<size; i++)
	{
		printf("%d - ",arr[i]);
		
		prom += arr[i];
		
		if (arr[i] > max) // chequeo de maximo
			max = arr[i];
			
		if (arr[i] < min) // chequeo de minimo
			min = arr[i];
	}
	
	printf("\nValor maximo: %d\n",max);
	printf("Valor minimo: %d\n",min);
	
	return prom / size; // calculo promedio
}

int BuscarIndice(int arr[], int size, int buscar)
{
	for (i=0; i<size; i++)
	{
		if (arr[i] == buscar)
			return i; // valor encontrado
	}
	
	return -1; // valor no esta en arreglo
}

int EliminarCopias(int arr[], int size)
{
	int j, aux, newSize=size;
	
	for(i=0;i<size;i++)
	{
		aux = arr[i];
		for (j=i+1;j<size;j++)
		{
			if (arr[j] == aux && arr[j] != 0)
			{
				arr[j] = arr[j+1];
				arr[j+1] = 0;
				newSize--;
			}
			if (arr[j] == 0)
			{
				arr[j] = arr[j+1];
				arr[j+1] = 0;
			}
		}
	}
	
	return newSize;
}

int main()
{
	int array[] = {6, 3, 1, 3, 5, 6, 4, 2};
	int arraySize = sizeof(array) / sizeof(array[0]);
	
	printf("--Ejercicio 1--\n");
	NumeroParImpar(1);
	NumeroParImpar(2);
	
	
	printf("\n--Ejercicio 2--\n");
	NumeroPrimo(5);
	NumeroPrimo(16);
	
	
	printf("\n--Ejercicio 3--\n");
	printf("El promedio de los numeros en el arreglo es: %f\n",PromedioMinMax(array, arraySize));
	
	
	printf("\n--Ejercicio 4--\n");
	printf("Indice de valor buscado: %d\n",BuscarIndice(array,arraySize,0));
	printf("Indice de valor buscado: %d\n",BuscarIndice(array,arraySize,2));
	
	
	printf("\n--Ejercicio 5--\n");
	printf("Arreglo Original: ");
	for (i=0;i<arraySize; i++)
		printf("%d - ",array[i]);
		
	printf("\nTamano Original: %d\n", arraySize);
	arraySize = EliminarCopias(array, arraySize);
	printf("Nuevo Tamano: %d\n", arraySize);
	arraySize = EliminarCopias(array, arraySize);
	printf("Nuevo Tamano: %d\n", arraySize);
	
	printf("Nuevo Arreglo: ");
	for (i=0; i<arraySize; i++)
		printf("%d - ", array[i]);
	
	return 0;
}
