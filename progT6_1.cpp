/* 
Autor: Franciscomilan
Realizado: 07/04/22
Escuela: Universidad UVM
Materia: Programacion Estructurada
Profesor: Armando Cruz
Ciclo: 01/2022
Descripcion: Programa en C que conforma la tarea 6, programa que utiliza la estrcutura de alumno y 
almacena los datos de 10 alumnos en un arreglo de la estructura alumno, con las siguientes opciones
0 para Salir
1 para Agregar alumnos
2 para Imprimir
3 para Alumnos aprobados
4 para Alumnos reprobados
5 para Promedio del grupo
6 para Porcentaje de alumnos aprobados 
y emplea filtros para la materia programacion estructurada
*/

//Librerias
#include<stdio.h>
#include<stdlib.h>
#include"miLibreria.h"

//Declaraciones globales
#define MAX 10	
struct alumno {
	char nombre[30];
	float promedio;
	int faltas;
};	
int n=0; 

//Prototipos o encabezado de funcion
int menu();
void agregar(struct alumno x[]);
void imprimir(struct alumno x[], int tipo); 
void promedioGrupo (struct alumno x[]);
void porcentajeAprobados (struct alumno x[]);

//Funcion menu
int main () {
	int op;
	struct alumno grupo[MAX];	
	do {
		op=menu();
		switch(op) {
			case 0: printf(" - Adios - \n");
				break;
			case 1: agregar(grupo);
				break;
			case 2: imprimir(grupo,0);
				break;
			case 3: imprimir(grupo,1);
				//Aprobados
				break;
			case 4: imprimir(grupo,2);
				//Reprobados
				break;
			case 5: promedioGrupo(grupo);
				//promedio
				break;
			case 6: porcentajeAprobados(grupo);
				//porcentaje
				break;
		}
	}while(op!=0);
	//Retorno
	return 0;
}

//Funciones
int menu() {
	//Variables
	int opcion;
	printf(" --------------- MENU ------------- ");
	printf(" 0. Salir \n");
	printf(" 1. Agregar alumnos \n");
	printf(" 2. Imprimir \n");
	printf(" 3. Alumnos aprobados\n");
	printf(" 4. Alumnos reprobados \n");
	printf(" 5. Promedio del grupo \n");
	printf(" 6. Porcentaje de alumno aprobados \n");
	opcion=leerd(" Seleccionar una opcion: ", 0,6);
	return opcion;
}

//Funcion agregar
void agregar (struct alumno x[]) {
	int pregunta;
	while (n<MAX) {
		leers("Nombre: ", x[n].nombre,30); 
		x[n].promedio=leerf("Promedio: ",0,10);
		x[n].faltas=leerd(" Faltas: ", 0, 32);
		pregunta=leerd(" Agregar otro alumno? (1-Si, 0-No): ",0,1);
		n++;
		if (pregunta==0) {
			break;
		}	
	}
	if (n==MAX) {
		printf(" Arreglo lleno ! \n");
		system("PAUSE");
	}
}

		
//Funcion imprimir
void imprimir(struct alumno x[], int tipo) {
	//Variable local	
	char mensaje[20];
	switch(tipo) {
		case 0: strcpy(mensaje,"Totales");
			break;
		case 1: strcpy(mensaje, "Aprobados");
			break;
		case 2: strcpy(mensaje,"Reprobados");
			break;
	}
	//Salida de datos
	printf("----------Alumnos %s---------------------\n", mensaje);
	printf(" ------- DATOS DEL GRUPO ---------------\n");
	printf(" No.Alumno\t\t Nombre\t Faltas\t\t Promedio\n");
	printf("-----------------------------------------\n");
	//Ciclo for
	for (int i=0;i<n;i++) {
		int aprobados;
		switch(tipo) {
			case 0: printf("%2d \t %s30s \t %2d \t %4.1f \n",i+1,x[i].nombre, x[i].faltas,x[i].promedio);
				break;
			case 1: if (x[i].promedio>=7) {
					printf("%2d \t %s30s \t %2d \t %4.1f \n",i+1,x[i].nombre, x[i].faltas,x[i].promedio);
					aprobados++;
				}
				break;
			case 2: if (x[i].promedio<=7) {
					printf("%2d \t %s30s \t %2d \t %4.1f \n",i+1,x[i].nombre, x[i].faltas,x[i].promedio);
				}
				break;
			}
		}
	printf("----------------------------------------------------\n");
	system("PAUSE");
}


//Funcion promedio del grupo
void promedioGrupo (struct alumno x[]) {
	float suma=0, promedioA=0;
	int i=0;
	for (int i=0; i<n; i++) {
		suma=suma+x[i].promedio;
	}
	promedioA=suma/n;
	printf(" El promedio del grupo es: %4.1f \n", promedioA);
}

//Funcion para calcular el porcentaje
void porcentajeAprobados (struct alumno x[]) {
	float porcentajeApro=0;
	int aprobados=0;
	for (int i=0;i<n;i++) {
		if(x[i].promedio>=7 && x[i].faltas <=6) {
		aprobados++;	
		}
	}
	porcentajeApro=(aprobados*100/n);
	printf(" El porcentaje de alumnos aprobados es: %.1f\n",porcentajeApro);
}

