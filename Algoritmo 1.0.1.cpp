#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;

//Par�metro para as respostas dos IF'S
#define SIM "sim"
#define NAO "nao"
//Fim das constantes


//Fun��o que converte os bits para decimal
int conversao(int cont, int bit)
{
    if (cont==0)
    {
		return 1;
	}
	
    else 
		return bit*pow(bit, cont-1);
}
//Fim da fun��o
 
main()
{
	setlocale(LC_ALL, "Portuguese");
    int bit[10], decimal=0, cont=0, flag=1;
    char resp[5];

    do{
    	
        cout<<" O n�mero que voc� est� pensando � �mpar? (sim/nao)"<<endl;
		cout<<" ";
		cin>>resp;
		cout<<endl;
		

        if(strcmp(resp,SIM)==0)
        {
            cout<<" O n�mero que voc� est� pensando � 1? (sim/nao)"<<endl; 
		    cout<<" ";
            cin>>resp;
		    cout<<endl;
		    
/*
Se sim, flag recebe 0 para sair do la�o WHILE, joga para fun��o CONVERS�O o(s) bit(s) 
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
    
//Else if que nega o primeiro IF do la�o WHILE, agregando bit '0' no vetor BIT.
        else if (strcmp(resp,NAO)==0)
        {
			bit[cont]=0;
		}

/*
Esse if, enquanto n�o houver flag, faz com que a pergunta seguinte seja
coerente com a resposta anterior "N�O", para melhor experi�ncia do usu�rio. 
O cout que est� dentro se junta a primeira pergunta do la�o.
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
 	cout<<endl<<" Voc� pensou no n�mero "<<decimal<<".";

}
