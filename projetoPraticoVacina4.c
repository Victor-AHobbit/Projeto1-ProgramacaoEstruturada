//Nome completo: Victor Araújo da Silva Brito
//Matricula: UC21105910
//Curso: Ciências da Computação
//Nome completo:
//Matricula:
//Curso: 

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

int contagem = 0;
//Menu Geral
void adicionarUsuario(int *validarId, char *validarNome[][30], char *validarEmail[][30], char *validarSexo[][30], char *validarEndereco[][30], double *validarAltura, bool *validarVacina);
//^Pronto!
void infosUsuario(int idProcurado, int *infoId, char *infoNome[][30], char *infoEmail[][30], char *infoSexo[][30], char *infoEndereco[][30], double *infoAltura, bool *infoVacina);
//^Pronto!
void editarUsuario(int *editarId, char *editarNome[][30], char *editarEmail[][30], char *editarSexo[][30], char *editarEndereco[][30], double *editarAltura, bool *editarVacina);
//^Terminar!!!!
void buscarId(int *idBuscaId, char *idBuscaNome[][30], char *idBuscaEmail[][30], char *idBuscaSexo[][30], char *idBuscaEndereco[][30], double *idBuscaAltura, bool *idBuscaVacina);
//^Pronto!
void buscarEmail(int *idBuscaId, char *idBuscaNome[][30], char *idBuscaEmail[][30], char *idBuscaSexo[][30], char *idBuscaEndereco[][30], double *idBuscaAltura, bool *idBuscaVacina);
//^Pronto!
void listaUsuario(int *listarId, char *listarNome[][30], char *listarEmail[][30], char *listarSexo[][30], char *listarEndereco[][30], double *listarAltura, bool *listarVacina);
//^Pronto!
void backupUsuario(int *backupId, char *backupNome[][30], char *backupEmail[][30], char *backupSexo[][30], char *backupEndereco[][30], double *backupAltura, bool *backupVacina);
//^Pronto!

//ADICIONAR USUARIO ----- PRONTO!!!
void criarId(int *geraId);
void criarNome(char *geraNome[][30], int numeroUsuario);
void criarEmail(char *geraEmail[][30], int numeroUsuario);
void criarSexo(char *geraSexo[][30], int numeroUsuario);
void criarEndereco(char *geraEndereco[][30], int numeroUsuario);
void criarAltura(double *geraAltura, int numeroUsuario);
void criarVacina(bool *geraVacina, int numeroUsuario);

int main()
{
    //Variaveis BASE
    int menu = 1, idUsuario[1000];
    char nome[1000][30], email[1000][30], sexo[1000][30], endereco[1000][30];
    double altura[1000];
    bool vacina[1000];

    do
    { //Menu
        system("cls");
        printf("_-_-_-_-_-_-_-_-_-_- BEM VINDO A CENTRAL _-_-_-_-_-_-_-_-_-_-\n");
        printf("_-_-_-_-_-_-_-_ SELECIONE A OPCAO QUE DESEJA _-_-_-_-_-_-_-_\n\n");
        printf("1 - ADICIONAR usuario\n");
        printf("2 - EDITAR usuario\n");
        printf("3 - EXCLUIR usuario\n");
        printf("4 - BUSCAR usuario pelo ID\n");
        printf("5 - BUSCAR usuario pelo EMAIL\n");
        printf("6 - LISTA de usuarios cadastrados\n");
        printf("7 - BACKUP dos usuarios cadastrados\n");
        printf("8 - FECHAR O PROGRAMA\n\n");
        printf("_-_-_-_-_-_-_-_ DIGITE O NUMERO DA OPCAO PARA PROSSEGUIR_-_-_-_-_-_-_-_ \n");
        fflush(stdin);
        scanf("%d", &menu);

        while (menu < 1 || menu > 8)
        {
            printf("\nO valor selecionado nao esta disponivel! Digite entre 1 e 8 para continuar\n");
            fflush(stdin);
            scanf("%d", &menu);
        }

        switch (menu)
        {
        case 1:
            adicionarUsuario(idUsuario, nome, email, sexo, endereco, altura, vacina);
            break;
        case 2:
            editarUsuario(idUsuario, nome, email, sexo, endereco, altura, vacina);
            break;
        case 3:
            printf("hello world");
            break;
        case 4:
            buscarId(idUsuario, nome, email, sexo, endereco, altura, vacina);
            break;
        case 5:
            buscarEmail(idUsuario, nome, email, sexo, endereco, altura, vacina);
            break;
        case 6:
            listaUsuario(idUsuario, nome, email, sexo, endereco, altura, vacina);
            break;
        case 7:
            backupUsuario(idUsuario, nome, email, sexo, endereco, altura, vacina);
            break;
        default:
            menu = 8;
            printf("\n\n\n\nFechando programa...");
            break;
        }
    } while (menu != 8);
}

void adicionarUsuario(int *validarId, char *validarNome[][30], char *validarEmail[][30], char *validarSexo[][30], char *validarEndereco[][30], double *validarAltura, bool *validarVacina)
{

    int menu = 1;

    do
    {
        system("cls");
        printf("_-_-_-_-_-_-_-_ ADICIONAR USUARIO _-_-_-_-_-_-_-_\n");
        criarId(validarId);                       //gera o id
        criarNome(validarNome, contagem);         //Cria o nome
        criarEmail(validarEmail, contagem);       //Cria o email
        criarSexo(validarSexo, contagem);         //Cria o sexo
        criarEndereco(validarEndereco, contagem); //Cria o endereço
        criarAltura(validarAltura, contagem);     //Cria a altura
        criarVacina(validarVacina, contagem);     //Cria a vacina
        infosUsuario(contagem, validarId, validarNome, validarEmail, validarSexo, validarEndereco, validarAltura, validarVacina);
        system("cls");
        contagem++;
        do
        {
            printf("\nDeseja cadastrar outro usuario?( 1 - [SIM] || 2 - [NAO] ): ");
            fflush(stdin);
            scanf("%d", &menu);
        } while (menu < 1 || menu > 2);
    } while (menu == 1);
}

void criarId(int *geraId)
{
    srand(time(NULL));
    geraId[contagem] = (rand() % 1000);
    for (int i = 0; i < contagem; i++)
    {
        if (geraId[contagem] == geraId[i])
        {
            geraId[contagem] = (rand() % 1000);
            i = 0;
        }
    }
}

void criarNome(char *geraNome[][30], int numeroUsuario)
{
    do
    {
        printf("\nDigite o nome do usuario: ");
        fflush(stdin);
        gets(geraNome[numeroUsuario]);
    } while (strlen(geraNome[numeroUsuario]) < 2);
}

void criarEmail(char *geraEmail[][30], int numeroUsuario)
{
    do
    {
        printf("\nDigite o email do usuario: ");
        fflush(stdin);
        gets(geraEmail[numeroUsuario]);
        if ((strchr(geraEmail[numeroUsuario], '@') == NULL))
        {
            printf("Insira um @ no seu email para continaur...");
        }

    } while (strchr(geraEmail[numeroUsuario], '@') == NULL);
}

void criarSexo(char *geraSexo[][30], int numeroUsuario)
{
    do
    {
        printf("\nDigite seu sexo (Masculino, Feminino ou Nao declarar): ");
        fflush(stdin);
        gets(geraSexo[numeroUsuario]);

        if ((stricmp(geraSexo[numeroUsuario], "Feminino") != 0) && (stricmp(geraSexo[numeroUsuario], "Masculino")) != 0 && (stricmp(geraSexo[numeroUsuario], "Nao declarar")))
        {
            printf("Sexo digitado e invalido!\n");
        }
    } while ((stricmp(geraSexo[numeroUsuario], "Feminino") != 0) && (stricmp(geraSexo[numeroUsuario], "Masculino")) != 0 && (stricmp(geraSexo[numeroUsuario], "Nao declarar")));
}

void criarEndereco(char *geraEndereco[][30], int numeroUsuario)
{
    do
    {
        printf("\nDigite seu endereco: ");
        fflush(stdin);
        gets(geraEndereco[numeroUsuario]);
    } while (strlen(geraEndereco[numeroUsuario]) < 2);
}

void criarAltura(double *geraAltura, int numeroUsuario)
{
    do
    {
        printf("\nDigite sua altura(Valor entre 1 e 2): ");
        fflush(stdin);
        scanf("%lf", &geraAltura[numeroUsuario]);

        if (geraAltura[numeroUsuario] < 1 || geraAltura[numeroUsuario] > 2)
        {
            printf("\nAltura Invalida! Digite uma nova altura");
        }
    } while (geraAltura[numeroUsuario] < 1 || geraAltura[numeroUsuario] > 2);
}

void criarVacina(bool *geraVacina, int numeroUsuario)
{
    int confirmador = 1;
    char confirmarVacina[10];

    do
    {
        printf("\nDigite se ja tomou a vacina(Responder com sim ou nao): ");
        fflush(stdin);
        gets(confirmarVacina);
        if (stricmp(confirmarVacina, "Sim") == 0)
        {
            geraVacina[numeroUsuario] = true;
            confirmador = 0;
        }
        else if ((stricmp(confirmarVacina, "Nao") == 0))
        {
            geraVacina[numeroUsuario] = false;
            confirmador = 0;
        }
        else
        {
            printf("\nInvalido, digite apenas sim ou nao");
        }

    } while (confirmador == 1);
}

void infosUsuario(int idProcurado, int *infoId, char *infoNome[][30], char *infoEmail[][30], char *infoSexo[][30], char *infoEndereco[][30], double *infoAltura, bool *infoVacina)
{
    system("cls");
    printf("_-_-_-_-_-_-_-_-_-_-_INFORMACAO-_-_-_-_-_-_-_-_-_\n");
    printf("Id: %d\n", infoId[idProcurado]);
    printf("Nome: %s\n", infoNome[idProcurado]);
    printf("Email: %s\n", infoEmail[idProcurado]);
    printf("Sexo: %s\n", infoSexo[idProcurado]);
    printf("Endereco: %s\n", infoEndereco[idProcurado]);
    printf("Altura: %0.2lf\n", infoAltura[idProcurado]);
    if (infoVacina[idProcurado] == true)
    {
        printf("Vacina: Dose aplicada!\n");
    }
    else
    {
        printf("Vacina: Dose nao aplicada!\n");
    }
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    getch();
}

void editarUsuario(int *editarId, char *editarNome[][30], char *editarEmail[][30], char *editarSexo[][30], char *editarEndereco[][30], double *editarAltura, bool *editarVacina)
{
    int menu, IdPesquisar;
    char emailPesquisar[30];

    system("cls");
    printf("_-_-_-_-_-_-_-_-_-_-_EDICAO DE USUARIO-_-_-_-_-_-_-_-_-_\n");
    printf("\n1 - Procurar por Id");
    printf("\n2 - Procurar por Email");
    printf("\n3 - Voltar ao Menu");
    printf("\n_-_-_-_-_-_-_-_ DIGITE O NUMERO DA OPCAO PARA PROSSEGUIR_-_-_-_-_-_-_-_ \n");
    fflush(stdin);
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
        system("cls");
        printf("Digite o ID que deseja procurar: ");
        scanf("%d", &IdPesquisar);
        for (int i = 0; i < contagem; i++)
        {
            if (editarId[i] == IdPesquisar)
            {
                infosUsuario(i, editarId, editarNome, editarEmail, editarSexo, editarEndereco, editarAltura, editarVacina);
                do
                {
                    system("cls");
                    printf("_-_-_-_-_-_-_-_ SELECIONE A OPCAO QUE DESEJA _-_-_-_-_-_-_-_\n\n");
                    printf("1 - Editar nome\n");
                    printf("2 - Editar email\n");
                    printf("3 - Editar sexo\n");
                    printf("4 - Editar endereco\n");
                    printf("5 - Editar altura\n");
                    printf("6 - Editar vacina\n");
                    printf("7 - Voltar ao menu\n");
                    fflush(stdin);
                    scanf("%d", &menu);
                    do
                    {
                        switch (menu)
                        {
                        case 1:
                            criarNome(editarNome, i);
                            break;
                        case 2:
                            criarEmail(editarEmail, i);
                            break;
                        case 3:
                            criarSexo(editarSexo, i);
                            break;
                        case 4:
                            criarEndereco(editarEndereco, i);
                            break;
                        case 5:
                            criarAltura(editarAltura, i);
                            break;
                        case 6:
                            criarVacina(editarVacina, i);
                            break;
                        default:
                            break;
                        }
                        infosUsuario(i, editarId, editarNome, editarEmail, editarSexo, editarEndereco, editarAltura, editarVacina);
                    } while (menu < 1 || menu > 7);
                    do
                    {
                        printf("\nDeseja editar outra informacao?( 1 - [SIM] || 2 - [NAO] ): ");
                        fflush(stdin);
                        scanf("%d", &menu);
                    } while (menu < 1 || menu > 2);

                } while (menu == 1);

                break;
            }
        }
        break;
    case 2:
        system("cls");
        printf("Digite o EMAIL que deseja procurar: ");
        fflush(stdin);
        gets(emailPesquisar);
        for (int i = 0; i < contagem; i++)
        {
            if (strcmp(emailPesquisar, editarEmail[i]) == 0)
            {
                infosUsuario(i, editarId, editarNome, editarEmail, editarSexo, editarEndereco, editarAltura, editarVacina);

                do
                {
                    system("cls");
                    printf("_-_-_-_-_-_-_-_ SELECIONE A OPCAO QUE DESEJA _-_-_-_-_-_-_-_\n\n");
                    printf("1 - Editar nome\n");
                    printf("2 - Editar email\n");
                    printf("3 - Editar sexo\n");
                    printf("4 - Editar endereco\n");
                    printf("5 - Editar altura\n");
                    printf("6 - Editar vacina\n");
                    printf("7 - Voltar ao menu\n");
                    fflush(stdin);
                    scanf("%d", &menu);
                    switch (menu)
                    {
                    case 1:
                        criarNome(editarNome, i);
                        break;
                    case 2:
                        criarEmail(editarEmail, i);
                        break;
                    case 3:
                        criarSexo(editarSexo, i);
                        break;
                    case 4:
                        criarEndereco(editarEndereco, i);
                        break;
                    case 5:
                        criarAltura(editarAltura, i);
                        break;
                    case 6:
                        criarVacina(editarVacina, i);
                        break;
                    default:
                        break;
                    }
                    infosUsuario(i, editarId, editarNome, editarEmail, editarSexo, editarEndereco, editarAltura, editarVacina);
                    do
                    {
                        printf("\nDeseja editar outra informacao?( 1 - [SIM] || 2 - [NAO] ): ");
                        fflush(stdin);
                        scanf("%d", &menu);
                    } while (menu < 1 || menu > 2);
                } while (menu == 1);

                break;
            }
        }
        break;
    default:
        break;
    }
}

void buscarId(int *idBuscaId, char *idBuscaNome[][30], char *idBuscaEmail[][30], char *idBuscaSexo[][30], char *idBuscaEndereco[][30], double *idBuscaAltura, bool *idBuscaVacina)
{
    int menu, IdPesquisar;
    do
    {
        system("cls");
        printf("Digite o ID que deseja procurar: ");
        scanf("%d", &IdPesquisar);
        for (int i = 0; i < contagem; i++)
        {
            if (idBuscaId[i] == IdPesquisar)
            {
                infosUsuario(i, idBuscaId, idBuscaNome, idBuscaEmail, idBuscaSexo, idBuscaEndereco, idBuscaAltura, idBuscaVacina);
                break;
            }
        }
        do
        {
            printf("\nDeseja procurar outro usuario?( 1 - [SIM] || 2 - [NAO] ): ");
            fflush(stdin);
            scanf("%d", &menu);
        } while (menu < 1 || menu > 2);
    } while (menu == 1);
}

void listaUsuario(int *listarId, char *listarNome[][30], char *listarEmail[][30], char *listarSexo[][30], char *listarEndereco[][30], double *listarAltura, bool *listarVacina)
{
    int menu;
    do
    {
        for (int i = 0; i < contagem; i++)
        {
            infosUsuario(i, listarId, listarNome, listarEmail, listarSexo, listarEndereco, listarAltura, listarVacina);
        }
        do
        {
            printf("\nDeseja repetir a lista ?( 1 - [SIM] || 2 - [NAO] ): ");
            fflush(stdin);
            scanf("%d", &menu);
        } while (menu < 1 || menu > 2);

    } while (menu == 1);
}

void buscarEmail(int *idBuscaId, char *idBuscaNome[][30], char *idBuscaEmail[][30], char *idBuscaSexo[][30], char *idBuscaEndereco[][30], double *idBuscaAltura, bool *idBuscaVacina)
{
    int menu = 1;
    char emailPesquisar[30];
    do
    {
        system("cls");
        printf("Digite o EMAIL que deseja procurar: ");
        fflush(stdin);
        gets(emailPesquisar);
        for (int i = 0; i < contagem; i++)
        {
            if (strcmp(emailPesquisar, idBuscaEmail[i]) == 0)
            {
                infosUsuario(i, idBuscaId, idBuscaNome, idBuscaEmail, idBuscaSexo, idBuscaEndereco, idBuscaAltura, idBuscaVacina);
                break;
            }
        }
        do
        {
            printf("\nDeseja procurar outro usuario?( 1 - [SIM] || 2 - [NAO] ): ");
            fflush(stdin);
            scanf("%d", &menu);
        } while (menu < 1 || menu > 2);
    } while (menu == 1);
}

void backupUsuario(int *backupId, char *backupNome[][30], char *backupEmail[][30], char *backupSexo[][30], char *backupEndereco[][30], double *backupAltura, bool *backupVacina)
{
    int menu = 1, validarRestaurar = 0, backupFeitoId[1000], backupContagem = 0;
    char backupFeitoNome[1000][30], backupFeitoEmail[1000][30], backupFeitoSexo[1000][30], backupFeitoEndereco[1000][30];
    double backupFeitoAltura[1000];
    bool backupFeitoVacina[1000];
    do
    {

        system("cls");
        printf("_-_-_-_-_-_-_-_ SELECIONE A OPCAO QUE DESEJA _-_-_-_-_-_-_-_\n\n");
        printf("\n1 - Fazer backup");
        printf("\n2 - Restaurar informacoes");
        printf("\n3 - Voltar ao menu\n");
        fflush(stdin);
        scanf("%d", &menu);
        do
        {
            printf("\nDigite apenas números de 1 a 3...");
        } while (menu < 1 || menu > 3);

        switch (menu)
        {
        case 1:
            system("cls");
            printf("Backup realizado!");
            for (int i = 0; i < contagem; i++)
            {

                backupFeitoId[i] = backupId[i];
                strcpy(backupFeitoNome[i], backupNome[i]);
                strcpy(backupFeitoEmail[i], backupEmail[i]);
                strcpy(backupFeitoSexo[i], backupSexo[i]);
                strcpy(backupFeitoEndereco[i], backupEndereco[i]);
                backupFeitoAltura[i] = backupAltura[i];
                backupFeitoVacina[i] = backupVacina[i];
                backupContagem = contagem;
            }
            backupContagem = contagem;
            validarRestaurar = 1;
            getch();
            break;
        case 2:
                system("cls");
                printf("Restauração realizada!");
                for (int i = 0; i < contagem; i++)
                {
                    backupId[i] = backupFeitoId[i];
                    strcpy(backupNome[i], backupFeitoNome[i]);
                    strcpy(backupEmail[i], backupFeitoEmail[i]);
                    strcpy(backupSexo[i], backupFeitoSexo[i]);
                    strcpy(backupEndereco[i], backupFeitoEndereco[i]);
                    backupAltura[i] = backupFeitoAltura[i];
                    backupVacina[i] = backupFeitoVacina[i];
                }
                contagem = backupContagem;
                getch();
            break;
        default:
            break;
        }
    } while (menu < 1 || menu > 3);
}