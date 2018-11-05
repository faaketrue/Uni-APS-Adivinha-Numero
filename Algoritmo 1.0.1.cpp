#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;

//Parâmetro para as respostas dos IF'S
#define SIM "sim"
#define NAO "nao"
//Fim das constantes


//Função que converte os bits para decimal
int conversao(int cont, int bit)
{
    if (cont==0)
    {
		return 1;
	}
	
    else 
		return bit*pow(bit, cont-1);
}
//Fim da função
 
main()
{
	setlocale(LC_ALL, "Portuguese");
    int bit[10], decimal=0, cont=0, flag=1;
    char resp[5];

    do{
    	
        cout<<" O número que você está pensando é ímpar? (sim/nao)"<<endl;
		cout<<" ";
		cin>>resp;
		cout<<endl;
		

        if(strcmp(resp,SIM)==0)
        {
            cout<<" O número que você está pensando é 1? (sim/nao)"<<endl; 
		    cout<<" ";
            cin>>resp;
		    cout<<endl;
		    
/*
Se sim, flag recebe 0 para sair do laço WHILE, joga para função CONVERSÃO o(s) bit(s) 
e no fim do algoritmo, retorna com a resposta.
*/

            if (strcmp(resp,SIM)==0)   
            {
                flag=0;
                bit[cont]=1;
            }
            
/*
Else para agregar mais de um bit '1' no vetor BIT, visto que se respondido SIM no de cima
em primeiro momento, retornaria como resposta o resultado "1".
*/
            else
            {
				bit[cont] = 1;
			}
 
        }
    
//Else if que nega o primeiro IF do laço WHILE, agregando bit '0' no vetor BIT.
        else if (strcmp(resp,NAO)==0)
        {
			bit[cont]=0;
		}

/*
Esse if, enquanto não houver flag, faz com que a pergunta seguinte seja
coerente com a resposta anterior "NÃO", para melhor experiência do usuário. 
O cout que está dentro se junta a primeira pergunta do laço.
*/
        if(flag!=0)
		{	
            cout<<"\n Beleza. Agora, se dividindo por dois o seu numero, me responda:";
		}     

//Contador para controle.
        cont++;  
		      		
    }while(flag!=0);
 
    for (int i=0; i<cont; i++)
	decimal += bit[i]*pow(2,i);


 	system("cls"); //Limpa a tela para a resposta.
 	cout<<endl<<" Você pensou no número "<<decimal<<".";

}
