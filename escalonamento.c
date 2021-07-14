#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int split(char tarefa[32],int pos1[],int pos2[],int pos3[], int i){
	
	char primeiro[5];
	char segundo[5];
	char terceiro[5];
	int j = 0;


	char *token = strtok(tarefa, "#");	
	while (token != NULL && j < 3){
		
		
		if (j == 0){
			strcpy(primeiro, token);
			pos1[i]= atoi(primeiro);	   
		}

		if (j == 1){
			strcpy(segundo, token);
			pos2[i] = atoi(segundo);  
		}

		if (j == 2){
			strcpy(terceiro, token);
			pos3[i] = atoi(terceiro);
		}	
		
        token = strtok(NULL, "#");
        j++;
        
    }
    return pos1[i],pos2[i],pos3[i];
}



int escal(int pos1[],int pos2[],int pos3[], int calc[], int tme[], float *valor_tme, int i){
	
	//CALC = TEMPO ONDE O PROCESSO SE ENCERROU
	//TME = TEMPO QUE O PROCESSO FICOU PARADO
	if (i == 0){
		calc[i] = pos2[i] + pos3[i];
		tme[i] = pos2[i] - pos2[i];
		printf("PROCESSO     TEMPO\n");
		printf("   %d      |    %d\n",i+1, pos2[i] - pos2[i]);
	}else{
		calc[i] = calc[i-1] + pos3[i];
		tme[i] = calc[i-1] - pos2[i];
		printf("   %d      |    %d\n",i+1, calc[i-1] - pos2[i]);
	}
	*valor_tme = tme[i] + *valor_tme;
	
return *calc;
}

int calc_tme (float *valor_tme, int n){

	*valor_tme = (*valor_tme/n);
	


return *valor_tme;
}


int main (int argc, char **argv){	
	int n = -1, i = 0;
	float *valor_tme;
	 	
	scanf("%d", &n);

	int pos1[n] , pos2[n], pos3[n], calc[n], tme[n]; 
	char tarefa[32];

	valor_tme = (float *) malloc (1*sizeof(float )); 

	for(i = 0; i < n; i++){

		scanf("%s", tarefa);
		
		//Reparte as 3 primeiras posições
		split(tarefa, pos1, pos2, pos3,i);
		
		//Calcula o tempo de processamento de cada processo
		escal(pos1, pos2, pos3,calc,tme, valor_tme, i);

	}

	//Calcula o valor final de TME
 	calc_tme(valor_tme, n);
	printf("\nTME = %.2f", *valor_tme);

	return EXIT_SUCCESS;
}
