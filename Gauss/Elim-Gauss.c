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
					matriz2[i][j]=matriz[i][j];
				}
			}
		}	
	}	
	
	//Se verifica si la matriz tiene filas con 0 o empieza con 0 y las acomoda
	//Intercambio de filas
	int a,k,auxiliar,auxiliar2,filaConCeros, bandera, bandera2;
	bandera=-1;
	bandera2=0;
	a=0;
	j=0;
	for(k=a;k<m-1;k++){
		if (matriz2[k][0]==0){
			//Verificar si hay una fila con ceros
			bandera=1;
			while(bandera==1 && j<=n){
				for(j;j<=n;j++){
					if (matriz2[k][j]!=0){
						bandera=0;//No hacer nada
						j=n+1;
					}
					else{
						bandera=1; //Cambiar al fina
						filaConCeros=k;
					}
				}
			}
			if (bandera==1){ //Intercambio de fila con ceros 
				for (j=0;j<=n;j++){ //
					auxiliar2=matriz2[filaConCeros][j];//
					matriz2[filaConCeros][j]=matriz2[m-1][j];
					matriz2[m-1][j]=auxiliar2;
				}
			}
			else{
				for (j=0;j<=n;j++){ //
					if (matriz2[k+1][j]!=0){
						auxiliar=matriz2[k][j];
						matriz2[k][j]=matriz2[k+1][j];
						matriz2[k+1][j]=auxiliar;
					}
					else{
						k++;
						j=0;
					}
				}
			}
		}
		bandera=-1;
		a=0;
	}
	
	//Algoritmo para Gauss
	//Preguntar si el primer numero es diferente de cero de la primera columna
	int filas, columnas,contador,contador2, bandera3;//new
	float x,numerador,denominador;
	k=0;
	bandera3=0;//new
	
	if (matriz2[k][0]!=0)
	{
		contador=0;
		contador2=0; //NEW
		while (contador<m-1)
		{
			filas=contador+1;
			for(filas;filas<m;filas++){
				columnas=contador;
				contador2=columnas;//new
				numerador=matriz2[filas][columnas];
				denominador=matriz2[contador][contador];
				while (denominador == 0.00){ // para que no sea x/0; /NEW
					numerador=matriz2[filas][contador+1];
					denominador=matriz2[contador][contador+1];
					contador++;//new
					bandera3=3;//NEW
				}
				x=(numerador/denominador);
				if(bandera3=3){//new
					columnas=contador;//new
				}//new
				for(columnas;columnas <= n; columnas++){  
					matriz2[filas][columnas]=-1*matriz2[contador2][columnas]*x + matriz2[filas][columnas];//new
				}
				if (bandera2==1)
				{
					for (i = m-1; i <m; i++) {
						for (j = 0; j <=n; j++){
							matriz2[i][j]=0;
						}
					}
				}
				//se hace con la siguiente fila
			}
			//siguiente columna para escalonar
			contador=contador2;//new
			contador++;
		}
	}
	//OUTPUT EN ARCHIVO DE TEXTO
	freopen ("output1.txt", "w", stdout);
	for (i = 0; i < m; i++) {
		for (j = 0; j <=n; j++){
			printf ("%.2f\t", matriz2[i][j]);
		}
		printf ("\n");
	}
	fclose (stdout);
	return EXIT_SUCCESS;
}
