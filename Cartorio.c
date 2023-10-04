#include <stdio.h>     // biblioteca de comunicação com o usuario 
#include <stdlib.h>   // biblioteca de alocação de espaço em memoria 
#include <locale.h>  // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsavel de cuidar das string

int registro() // Função resposavel por cadastrar os usuários no sistema
{     // Inicio da criação de variaveis / string
	  char arquivo[40];
	  char cpf[40];
	  char nome[40];
	  char sobrenome[40];
	  char cargo[40];
	  // Final da criação de variaveis / string
	  
	  printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
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
	  printf("Não foi possivel abrir o arquivo,não localizado!.\n");
    }
    
    while(fgets(conteudo, 200, file)!= NULL)
    {
      printf("\nEssas são as informações do usuário: ");
      printf("%s", conteudo);
      printf("\n\n");
    	
	}
	
	  system("pause");
	  fclose(file);
     
}

int deletar()
{
      char cpf[40];
    
      printf("Digite o CPF do usuário a ser deletado: ");
      scanf("%s",cpf);
    
    
      FILE *file;
      file = fopen(cpf,"r");
    
      if(file == NULL)
    {
      fclose(file);
      printf("O usuário não se encontra no sistema!.\n");
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
	  int opcao=0; // definindo opções
	  int x=1;
	
	  for(x=1;x=1;)
	{
	  system("cls"); // Responsavel por limpar a tela 
	
	setlocale(LC_ALL,"Portuguese"); // definindo linguagem
	
        printf("### Cartório da EBAC ###\n\n"); // inico do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar   nomes\n\n");
	    printf("Opção:"); // fim do menu
	
	    scanf("%d", &opcao); // armazenando as escolhas do usuário 
	
	    system("cls"); // Responsavel por limpar a tela 
	
	
	    switch(opcao) // inico de seleção de funções
    {
	    	
	    case 1:
	    registro(); // Chamada de funções
		break;
		
		case 2:
		consulta(); // Chamade de funções
		break;
		
		case 3:
		deletar(); // Chamada de funções
		break;
		
		default:
		printf("Essa opção não esta disponivel!\n");
		system("pause");
		break;
			
		
    }

	
}	  
}

