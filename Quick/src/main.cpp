//==============================================================
// --- Bibliotecas
//==============================================================
#include <iostream>

//==============================================================
// --- Protótipo das funções ---
//==============================================================
void quick(int *array, int i);

//==============================================================
// --- Função Principal ---
//==============================================================
using namespace std;

int main()
{
	cout << "=== Algoritmo de ordenação Quicksort ===" << endl << endl;
	int num = 1,
		  i = 0;
		
	int *ptr = (int*) malloc(sizeof(int));

	if(ptr == NULL)
	{
		puts("Erro na alocação.");
		exit(1);
	}

	cout << "Insira um inteiro positivo para adicioná-lo ao array (0 para sair)" << endl;
	
	while(num)
	{
		cin >> num;
		
		if(!num) break;			//ignora o número 0 digitado pelo usuário

		if(i)
		{
			int *ptr_temp = (int*) realloc(ptr, (i+1) * sizeof(int));

			if(ptr_temp == NULL)
			{
				puts("Erro na realocação.");
				exit(1);
			}

			ptr = ptr_temp;		
			
		} // end if realloc i>0
		
		ptr[i] = num;
		i++;
		
	} // end while 

	int array[i];

	for(int j=0; j<i; j++)				//faz a cópia do 
		array[j] = ptr[j];

	free(ptr);
		ptr = NULL;
			
	quick(array, i);

	cout << endl;

	cout << "=== Vetor ordenado === "<< endl << endl; 
	
	for(int j=0; j<i; j++)
		cout << array[j] << " ";

	cout << endl;
	
	return 0;
	
} // end main
//==============================================================
// --- Desenvolvimento das Funções ---
//==============================================================
void quick(int *array, int i)
{
	if(i<2) return; 						//se o tamanho do array for menor que 2 elementos (caso base)
	
	int index_pivo = i/2,					//define a posição do pivo 
	    pivo = array[index_pivo],			//define o valor do pivo conforme sua posição no vetor 
		cont_menor = 0,
		cont_maior = 0;

	for(int k=0; k<i; k++)
	{
		if(k == index_pivo) continue;			//ignora o pivo, separando-o dos subvetores
		
		if(array[index_pivo] > array[k])		//conta quantos elementos do vetor são menores que o pivo
			cont_menor++;
	

		if(array[index_pivo] <= array[k])		//conta quantos elementos do vetor são maiores que o pivo
			cont_maior++;
	}

	int menor[cont_menor];				//cria um vetor para os valores menores
	int maior[cont_maior];				//cria um vetor para os valores maiores

	int index_menor = 0;
	int index_maior = 0;

	for(int k=0; k<i; k++)				//adiciona os elementos do vetor para os subvetores
	{
		if(k == index_pivo) continue;		
		
		if(array[index_pivo] > array[k])
		{
			menor[index_menor] = array[k];
			index_menor++;
		}

		if(array[index_pivo] <= array[k])
		{
			maior[index_maior] = array[k];
			index_maior++;
		}
			
	} // end for subvetores

	quick(menor, cont_menor);
	quick(maior, cont_maior);	//retorna a junção + ordenação dos vetores (caso recursivo)

	int index_array = 0;

	for(int j=0; j<cont_menor; j++)
	{
		array[index_array] = menor[j];			//coloca os elementos do vetor menor no array principal
		index_array++;
	}

	array[index_array] = pivo;
	index_array++;

	for(int j=0; j<cont_maior; j++)
	{
		array[index_array] = maior[j];
		index_array++;
	}
}

//==============================================================
// --- Fim do Programa
