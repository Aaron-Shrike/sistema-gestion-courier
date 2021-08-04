#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

#define MAX 20
#define LIM 50

// operacions basicas de datos simples

int leeEntero(char msje[], int min, int max,char msje1[])
{
	int num;

   	do{
   		printf("%s", msje);
      	scanf("%d", &num);
      	if(num<min || num>max){
      		printf("%s\n", msje1);
      	}
   	}while(!(num>=min && num<=max));

  	return num;
}

float leeReal(char msje[], float min, float max, char msje1[])
{
	float num;

  	do{
     	printf("%s", msje);
     	scanf("%f", &num);
     	if(num<min || num>max){
      		printf("%s\n", msje1);
		}
  	}while(!(num>=min && num<=max));

  	return num;
}

//Adicionales
char leeSexo(char msje[])
{
	char rpta;

   	cout << " F : Femenino" <<endl;
   	cout << " M : Masculinoino" <<endl;
   	do{
   		printf("%s", msje);
      	fflush(stdin);
      	scanf("%c",&rpta);
   	}while(!(rpta=='F' || rpta== 'M'));
   	
   	return rpta;
}

char leeCaracter(char msje1[],char msje2[],char A,char B,char msje[]){
	char rpta;

   	cout << msje1 <<endl;
   	cout << msje2 <<endl;
   	do{
   		printf("%s", msje);
      	fflush(stdin);
      	scanf("%c",&rpta);
   	}while(!(rpta==A || rpta== B));

   	return rpta;
}

// HORA
int hora()
{
	/*
   struct tm {
   	int tm_sec;   // seconds of minutes from 0 to 61
      int tm_min;   // minutes of hour from 0 to 59
      int tm_hour;  // hours of day from 0 to 24
      int tm_mday;  // day of month from 1 to 31
      int tm_mon;   // month of year from 0 to 11
      int tm_year;  // year since 1900
      int tm_wday;  // days since sunday
      int tm_yday;  // days since January 1st
      int tm_isdst; // hours of daylight savings time
   }
	*/

	// fecha/hora actual basado en el sistema actual
	time_t now = time(0);

	// Objeto de una estructura tm con fecha/hora local
	tm * tiempo = localtime(&now);

	char  *dia_semana[7] = {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};

	char *mes[12] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre",
		"Octubre","Noviembre","Diciembre"};

	int year = 1900 + tiempo->tm_year;

	// Formato=hoy miercoles, 27 de mayo del 2015
	cout << "Hoy " << dia_semana[tiempo->tm_wday] << ", ";
	cout << tiempo->tm_mday << " de " << mes[tiempo->tm_mon] << " del " << year << endl;
	cout << tiempo->tm_hour << ":" << tiempo->tm_min << ":" << tiempo->tm_sec << endl;


   	// convertir ahora a forma de cadena(string)
   	char* dt = ctime(&now);

   	cout << "La fecha y hora local es: " << dt << endl;

   	// Convertir ahora a tm struct para UTC
   	tm *gmtm = gmtime(&now);
   	dt = asctime(gmtm);
   	cout << "La UTC fecha y hora es:"<< dt << endl;

   	return NULL;


   /*
	//Esto devuelve el tiempo de calendario actual del sistema en el número de segundos transcurridos desde el 1 de enero de 1970. Si el sistema no tiene hora, se devuelve .1.
	time_t time (time_t * time);

   Ej:
      time_t variable = time(0);
   	time_t variable = time(&variable);

	//Esto devuelve un puntero a una cadena del formulario día mes año horas: minutos: segundos año \ n \ 0 .
	char * ctime (const time_t * time);

   Ej:
   	char *nombreVariable = ctime(variable);

	//Esto devuelve un puntero a la estructura tm que representa la hora local.
   struct tm * localtime (const time_t * time);

   Ej:
   	tm *nombreVariable = localtime(variable);

	//Esto devuelve un valor que se aproxima a la cantidad de tiempo que el programa de llamada ha estado ejecutándose. Se devuelve un valor de .1 si el tiempo no está disponible.
   clock_t clock (void);

   Ej:

	//Esto devuelve un puntero a una cadena que contiene la información almacenada en la estructura apuntada por el tiempo convertido en la forma: día mes fecha horas: minutos: segundos año \ n \ 0
   char * asctime (const struct tm * time);

   Ej:

	//Esto devuelve un puntero a la hora en forma de una estructura tm. El tiempo se representa en el Tiempo Universal Coordinado (UTC), que es esencialmente el Tiempo Medio de Greenwich (GMT).
   struct tm * gmtime (const time_t * time);

   Ej:
   	tm *nombreVariable = gmtime(variable);

	//Esto devuelve el equivalente en tiempo del calendario del tiempo encontrado en la estructura señalada por tiempo.
   time_t mktime (struct tm * time);

   Ej:

	//Esta función calcula la diferencia en segundos entre time1 y time2.
   doble difftime (time_t time2, time_t time1);

   Ej:

	//Esta función se puede utilizar para formatear la fecha y la hora en un formato específico.
   size_t strftime ();

   Ej:

   */
}
