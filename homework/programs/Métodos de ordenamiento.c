#include <stdio.h>
#include <stdlib.h>

void Ingresar(int n, int *arreglo);
void Insert_Sort(int n, int *arreglo);
void Merge_Sort(int * arreglo, int head, int tail);
void Merge(int *arreglo, int mitad, int head, int tail);

int main(){
    int n,i, *arreglo;

    printf("No. de numeros ingresar:");
    scanf("%d", &n);
    
   
    
    arreglo = (int*)malloc(n * sizeof(int));
    if(arreglo == NULL){
        printf("No se pudo asignar memoria\n");
        return 1;
    }

    Ingresar(n, arreglo);
    
    Insert_Sort(n, arreglo);
    printf("\n");
    Merge_Sort(arreglo,0, n-1);
    
    
    printf("Arreglo ordenado con Merge Sort:\n[ ");
    for(i = 0; i < n; i++){
        printf("%d ", arreglo[i]);
    }
    printf("]\n\n");


    free(arreglo);
}

void Ingresar(int n, int *arreglo){
    int i;

     printf("Ingresa %d numeros separados por espacio:\n", n);

    for(i = 0; i < n; i++){
        scanf("%d", &arreglo[i]);
    }

    printf("Arreglo ingresado:\n[ ");
    for(i = 0; i < n; i++){
        printf("%d ", arreglo[i]);
    }
    printf("]\n");
}

void Insert_Sort(int n, int *arreglo){
    int i, j, temp;

    for(i = 1; i < n; i++){
        temp = arreglo[i];
        j = i - 1;

        while(j >= 0 && arreglo[j] > temp){
            arreglo[j+1] = arreglo[j];
            j--;
        }

        arreglo[j+1] = temp;
    }
	  printf("\n");
    printf("Arreglo Ordenado con 'Insert Sort':\n[ ");
    for(i = 0; i < n; i++){
        printf("%d ", arreglo[i]);
    }
    printf("]\n");
}

void Merge_Sort(int * arreglo, int head, int tail){
	if(head<tail){
			int mitad= (head+tail)/2;
			Merge_Sort(arreglo,head,mitad);
			Merge_Sort(arreglo,mitad+1,tail);
			
			Merge(arreglo, mitad, head, tail);
	}
	
}
void Merge(int *arreglo, int mitad, int head, int tail){
	int i,j,k;
	int n1= mitad-head+1;
	int n2= tail-mitad;
	
	 int *I = (int*)malloc(n1*sizeof(int));
	int *D = (int*)malloc(n2*sizeof(int));
	
	for(i=0;i<n1;i++){
		I[i]=arreglo[head+i];
	}
	
	for(j=0;j<n2;j++){
		D[j]=arreglo[mitad+1+j];
		
	}
	
	i=0,j=0,k=head;
	while(i<n1 && j<n2){
		if(I[i]<=D[j]){
			arreglo[k]= I[i];
			i++;
			
		}else{
			arreglo[k]=D[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		arreglo[k]=I[i];
		i++;
		k++;
	}
	
	while(j<n2){
		arreglo[k]=D[j];
		j++;
		k++;
	}
	
	free(I);
	free(D);
	
}

