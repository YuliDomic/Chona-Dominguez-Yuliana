#include <stdio.h>
#include <stdlib.h>

int NumPares(int pares[10]){
	int i;
	for(i=0;i<10;i++){
		pares[i]=(i+1)*2;
	}

}

int CambioNumero(int ultimo,int pares[]){
	int i;

		if(ultimo>=0 && ultimo<10) {
		pares[ultimo]=-1;	
		}
		printf("\n");
		printf(".........................................Arreglo con -1.............................\n");
		for(i=0;i<10;i++){
			printf("|%d|\t", pares[i]);
		}
	
}


int main(){
	int i,pares[10],cuenta,ultimo;
	
	NumPares(pares);
	printf("Ingrese su numero de cuenta: ");
	scanf("%d",&cuenta);
	ultimo = cuenta%10;
	
	printf(".......................................Arreglo Inverso..............................\n");
	for(i=9;i>=0;i--){
			printf(" |%d| \t",pares[i]);
	}
	printf("\n");
	
	CambioNumero(ultimo,pares);
	return 0;
}
