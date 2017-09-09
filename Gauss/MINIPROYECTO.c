#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fichero;
	int i,j,ecuaciones,variables, matriz[10][10];
	float	matriz2[10][10];
	
	int m,n;
	
	fichero = fopen("input1.txt","r");
	fscanf(fichero, "%d %d" ,&ecuaciones, &variables);
	m=ecuaciones;
	n=variables;
	printf ("Las ecuaciones son %d y las variables %d\n",m,n);
	
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			matriz[i][j]=0;
		}
	}
	
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			matriz2[i][j]=0;
		}
	}
	/* inicializa matriz a 0 */
	for (i = 0; i < m; i++){
		for (j = 0; j <= n; j++){
			//matriz[i][j] = 0;
			fichero = fopen("input1.txt","r");
			if (fichero==NULL)
			{
				printf( "No se puede abrir el fichero.\n" );
				system("pause");
				exit (EXIT_FAILURE);
			}
			i = 0;
			fscanf(fichero, "%d %d" ,&m, &n);
			while (1)
			{
				if (feof(fichero))
					break;
				
				for(i=0;i<m;i++)
				{
					for(j=0;j<=n;j++)
					{
						fscanf (fichero, "%d",&matriz[i][j]);
					}
					
				}
			}
			fclose(fichero);
			printf( "\nContenido del archivo de texto:\n" );
			for (i = 0; i < m; i++) {
				for (j = 0; j <=n; j++){
					printf ("%d\t", matriz[i][j]);
					matriz2[i][j]=matriz[i][j];
				}
				printf ("\n");
			}
		}	
	}	
	
	printf("\n");	
	printf("Esta es la matriz 2\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<=n;j++)
		{
			printf("%.2f\t",matriz2[i][j]);
		}
		printf("\n");
	}
	
	//Algoritmo para Gauss
	//Preguntar si el primer numero es diferente de cero de la primera columna
	int a,b,k,filas, columnas,contador,contador2,auxiliar,p;
	float x,numerador,denominador;
	k=0;
	for (k; k<=m; k++){
		if (matriz[k][0]!=0)
		{
			printf("HOLA");
			//Se hace el agoritmo
			contador=0;
			while (contador<m-1)
			{
				//numerador=matriz2[contador+1][contador];
				//denominador=matriz2[contador][contador];
				//x=(numerador/denominador);
				
				//printf("\nNumerador %.1f\t Denominador%.1f",numerador,denominador);
				//printf("\nx vale: %.2f", x);//Constante//Constante
				//
				//columnas=contador;
				filas=contador+1;
				
				for(filas;filas<m;filas++){
					printf("Las filas son %d____",filas);
					contador2=contador;
					columnas=contador;
					printf("contador2 %d %d columnas %d\n",contador2,contador2 + 1,columnas);
					
					numerador=matriz2[contador2 + 1*filas - contador][contador];
					denominador=matriz2[contador][contador];
					if (denominador == 0){ // para que no sea x/0;
						numerador=matriz2[contador2 + 1*filas - contador][contador+1];
						denominador=matriz2[contador][contador+1];
						
					}
					x=(numerador/denominador);
					printf("Numerador %.2f\n",numerador);
					printf("Numerador %.2f\n",denominador);
					for(columnas;columnas <= n; columnas++){  
						printf("\nEl valor de columnas es : %d",columnas);
						matriz2[filas][columnas]=-1*matriz2[filas-1*filas+contador][columnas]*x + matriz2[filas][columnas];
						printf("\nLa matriz de posicion(%d,%d)es %.4f:",filas,columnas,matriz2[filas][columnas]);
						printf("\n");
					}
					//se hace con la siguiente fila
					printf("\n");
					contador2++;
				}
				//siguiente columna para escalonar
				contador++;
				printf("\n El contador es %d\n",contador);
			}
			k=m;
			/*cambiar var por n*/
		}
		else{
			k++;
			//Intercambio de filas
			for(k;k<m;k++){
				j=0;
				if (matriz[k][0]!=0){
					for (p=0;p<=n;p++){ //p son columnas 0 hasta 3
						auxiliar=matriz2[k][j];//
						matriz2[k][j]=matriz2[0][j];
						matriz2[0][j]=auxiliar;
						j++; //j son las columnas de la primera fila
					}
					break;
				}
			}
			printf("\nMatriz con fila intercambiada\n");
			for(i=0;i<m;i++)
			{
				for(j=0;j<=n;j++)
				{
					printf("%.2f\t",matriz2[i][j]);
				}
				printf("\n");
			}
		}
	}
	printf("\n Matriz final \n\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j <=n; j++){
			printf ("%.2f\t", matriz2[i][j]);
		}
		printf ("\n");
	}
	
	return EXIT_SUCCESS;
}

