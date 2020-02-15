#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Este programa simula ser un restaurante
	muestra un menú e imprime el ticket de consumo
*/

int menu();
void impticket(int comida, int bebida, int postre);
int comida, bebida, postre;
int exc = 173, preg = 168, a = 160, e = 130, i = 161, o = 162, u = 163, n = 164, din = 36;

main(){
	int op, resp, cont = 0;

	printf("\t\t\t\a%cBienvenido al restaurante 'El Restaurador'!\n\n", exc);
	printf("%cDesea ordenar ya?\n1. S%c\t2.A%cn no\n", preg, i, u);
	scanf("%d", &resp);
	while(op != 1){
		if(resp == 1){
			op = 1;
		}
		if(resp == 2){
			op = 2;
		}
	switch(op){
		case 1:
			menu();
			system("PAUSE");
			system("cls");
			impticket(comida, bebida, postre);
			printf("\n\n\t\t\t\a%cProvecho, vuelva pronto!\n", exc);
			break;
		case 2:
			cont++;
			system("cls");
			printf("%cY ahora?\n1. S%c\t2.%cQue no!\n", preg, i, exc);
			scanf("%d", &resp);
			if(cont == 5){
				printf("%cEntonces qu%c hace aqu%c?\n%cYa v%cyase!\n", preg, e, i, exc, a);
				return 0;
			}
			break;
		default:
			system("cls");
			printf("Esa opci%cn no ven%ca en las respuestas\n", o, i);
			printf("%cDesea ordenar ya?\n1. S%c\t2.A%cn no\n", preg, i, u);
			scanf("%d", &resp);
			break;
	}
	}
	system("PAUSE");
	return 0;
}

int menu(){

	do{
		system("cls");
		printf("%cQu%c va a comer? Tenemos\n", preg, e);
		printf("1.Sopa de camar%cn\t%c40\n2.Algo con mucha carne\t%c60\n3.Algo muy vegetariano\t%c35\n", o, din, din, din);
		scanf("%d", &comida);
		if((comida < 0) || (comida > 3)){
			printf("Elija una opci%cn v%clida\n", o, a);
			scanf("%d", &comida);
		}
	}while((comida < 0) || (comida > 3));
	do{
		system("cls");
		printf("Puede acompa%car su platillo con\n", n);
		printf("1.Un fresco vaso de agua %c11\n2.Vino \t\t\t%c83\n3.Un juguito \t\t%c32\n", din, din, din);
		scanf("%d", &bebida);
		if((bebida < 0) || (bebida > 3)){
			printf("Elija una opci%cn v%clida\n", o, a);
			scanf("%d", &bebida);
		}
	}while((bebida < 0) || (bebida > 3));
	do{
		system("cls");
		printf("%cCon cu%cl postre rematar%c su apetito?\n", preg, a, a);
		printf("1.Un flan\t\t%c15\n2.Arroz con leche\t%c24\n3.Gajitos de naranja\t%c28\n", din, din, din);
		scanf("%d", &postre);
		if((postre < 0) || (postre > 3)){
			printf("Elija una opci%cn v%clida\n", o, a);
			scanf("%d", &postre);
		}
	}while((postre < 0) || (postre > 3));
	printf("\n%cEsperamos que la comida sea de su agrado!\n", exc);

	return comida, bebida, postre;
}

void impticket(int comida, int bebida, int postre){
	FILE *ap;
	int pcomida, pbebida, ppostre, suma;
	time_t hora;
	char* fecha;

	ap = fopen("ticket.txt", "w");
	fprintf(ap, "---¡Restaurante 'El Restaurador'!---\n\n");

	if(comida == 1){
		pcomida = 40;
		fprintf(ap, "Sopa de camaron\t$%d\n", pcomida);
	}if(comida == 2){
		pcomida = 60;
		fprintf(ap, "Mucha carne\t$%d\n", pcomida);
	}if(comida == 3){
		pcomida = 35;
		fprintf(ap, "Mucho vegetal\t$%d\n", pcomida);
	}
	if(bebida == 1){
		pbebida = 11;
		fprintf(ap, "Vaso de agua\t$%d\n", pbebida);
	}if(bebida == 2){
		pbebida = 83;
		fprintf(ap, "Vino\t\t\t$%d\n", pbebida);
	}if(bebida == 3){
		pbebida = 32;
		fprintf(ap, "Juguito\t\t$%d\n", pbebida);
	}
	if(postre == 1){
		ppostre = 15;
		fprintf(ap, "Flan\t\t$%d\n", ppostre);
	}if(postre == 2){
		ppostre = 24;
		fprintf(ap, "Arroz con leche\t$%d\n", ppostre);
	}if(postre == 3){
		ppostre = 28;
		fprintf(ap, "Gajitos de naranja $%d\n", ppostre);
	}
	suma = pcomida + pbebida + ppostre;
	fprintf(ap, "\nTotal:\t\t%c%d", din, suma);
	fprintf(ap, "\n\n¡¡¡Muchas gracias por su preferencia!!!\n");
	fprintf(ap, "Atendió: Mauricio Díaz Segura\n");
	hora = time(NULL);
	fecha = ctime(&hora);
	(void) fprintf(ap, "Fecha: %s\n", fecha);
	fclose(ap);
	printf("%cSu ticket ha sido generado!", exc);
}