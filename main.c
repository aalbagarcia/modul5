/** 
 * Programa que comprueba si un número es un número de Armstrong.
 *
 * @file
 *
 */


# include <stdio.h>
# include <math.h>

//! Número máximo de elementos del stack
#define max 10

//! Índice de la último elemento del stack
int top=-1;

//! El stack...
int stack[max];

/**
 * Añade un elemento al stack
 */
void push(int);

/**
 * Saca el último elemento del stack
 */
int pop();

/**
 * Verifica si un número es de Armstrong o no
 *
 * @param a El número que queremos comprobar
 *
 * @return int 0 si es de Armstrong y 1 si no lo es
 */
int is_armstrong_number(int a);

/**
 * La función principal que es muy principal.
 */
void main(){   
	int n;   
	printf("Introduce un número entero");   
	scanf("%d",&n);   
	if (is_armstrong_number(n))      
		printf("%d es un número de armstrong \U0001F60E \n", n);   
	else printf("%d no es un número de armstrong \U0001F622 \n", n);
}

int is_armstrong_number(int numb){   
	int j, remainder, temp, count, value;   
	temp=numb;   
	count=0;   
	while(numb >0)   {      
		remainder=numb%10;      
		push(remainder);      
		count++;      
		numb=numb/10;   
	}   numb=temp;   
	value=0;   
	while(top >=0)   {      
		j=pop();      
		value=value+pow(j,count);   
	}   
	
	if(value==numb)
		return 1;   
	else 
		return 0;
}

void push(int m){   
	top++;   
	stack[top]=m;
}

int pop(){   
	int j;   
	if(top==-1)
		return(top);   
	else   
	{      
		j=stack[top];      
		top--;      
		return(j);   
	}
}
