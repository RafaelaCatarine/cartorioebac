#include <stdio.h>     // biblioteca de comunica��o com o usuario 
#include <stdlib.h>   // biblioteca de aloca��o de espa�o em memoria 
#include <locale.h>  // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca responsavel de cuidar das string

int registro() // Fun��o resposavel por cadastrar os usu�rios no sistema
{     // Inicio da cria��o de variaveis / string
	  char arquivo[40];
	  char cpf[40];
	  char nome[40];
	  char sobrenome[40];
	  char cargo[40];
	  // Final da cria��o de variaveis / string
	  
	  printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
	  scanf("%s", cpf); // %s refere-se as string
	  
	  strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	  
	  FILE *file; // cria o arquivo
	  file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever (write)
	  fprintf(file,cpf); // salvo o cpf
	  fclose(file); // fecha o arquivo
	  
	  file = fopen(arquivo, "a"); // Abrindo arquivo e o "a" significa atualizar 
	  fprintf(file, ",");
	  fclose(file);
	  
	  printf("Digite o nome a ser cadastrado: ");
	  scanf("%s", nome);
	  
	  file = fopen(arquivo, "a");
	  fprintf(file,nome);
	  fclose(file);
	  
	  file = fopen(arquivo, "a");
	  fprintf(file, ",");
	  fclose(file);
	  
	  printf("Digite o sobrenome a ser cadastrado: ");
	  scanf("%s", sobrenome);
	  
	  file = fopen(arquivo, "a");
	  fprintf(file,sobrenome);
	  fclose(file);
	  
	  file = fopen(arquivo, "a");
	  fprintf(file, ",");
	  fclose(file);
	  
	  printf("Digite o cargo a ser cadastrado: ");
	  scanf("%s", cargo);
	  
	  file = fopen(arquivo, "a");
	  fprintf(file,cargo);
	  fclose(file);
	  
	 
	  
	  
	  
	  
	  
}

int consulta()
{
	  setlocale(LC_ALL,"Portuguese"); // definindo linguagem
	
	  char cpf[40];
      char conteudo [200];
	
	  printf("Digite o CPF que deseja consultar: ");
	  scanf("%s", cpf);
	
	  FILE *file;
	  file = fopen(cpf,"r"); // o "r" significa ler(read)
	  
	  if(file== NULL)
    {   
	  printf("N�o foi possivel abrir o arquivo,n�o localizado!.\n");
    }
    
    while(fgets(conteudo, 200, file)!= NULL)
    {
      printf("\nEssas s�o as informa��es do usu�rio: ");
      printf("%s", conteudo);
      printf("\n\n");
    	
	}
	
	  system("pause");
	  fclose(file);
     
}

int deletar()
{
      char cpf[40];
    
      printf("Digite o CPF do usu�rio a ser deletado: ");
      scanf("%s",cpf);
    
    
      FILE *file;
      file = fopen(cpf,"r");
    
      if(file == NULL)
    {
      fclose(file);
      printf("O usu�rio n�o se encontra no sistema!.\n");
      system("pause");
    	
	}
	
      else if(file!= NULL)
    {
      fclose(file); 
      printf("Arquivo deletado com sucesso!\n");
      system("pause");
      remove(cpf);
	}
	
}   

int main() 
    {
	  int opcao=0; // definindo op��es
	  int x=1;
	
	  for(x=1;x=1;)
	{
	  system("cls"); // Responsavel por limpar a tela 
	
	setlocale(LC_ALL,"Portuguese"); // definindo linguagem
	
        printf("### Cart�rio da EBAC ###\n\n"); // inico do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar   nomes\n\n");
	    printf("Op��o:"); // fim do menu
	
	    scanf("%d", &opcao); // armazenando as escolhas do usu�rio 
	
	    system("cls"); // Responsavel por limpar a tela 
	
	
	    switch(opcao) // inico de sele��o de fun��es
    {
	    	
	    case 1:
	    registro(); // Chamada de fun��es
		break;
		
		case 2:
		consulta(); // Chamade de fun��es
		break;
		
		case 3:
		deletar(); // Chamada de fun��es
		break;
		
		default:
		printf("Essa op��o n�o esta disponivel!\n");
		system("pause");
		break;
			
		
    }

	
}	  
}

