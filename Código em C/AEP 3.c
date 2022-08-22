#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

///=========GLOBAIS=========
    int n; //cliente logado

    char cpf[20][20];
    char nome[20][150];
    char telefone[20][20];
    char email[20][150];
    char senha[20][30];
    char endereco[20][5][200];
    char cep[20][5][30];
    char cartao[20][5][100];

    char restaurante[3][150]={"Lanchonete do Ney", "Pizzaria do Mario", "Tabacaria sem Cancer"};

    char produto[3][5][100];
    char desc[3][5][100];
    float valor[3][5];

    char item[10][50];
    float total[10];
///===========================
void copiaClientes();
void copiaClientes();
void copiaProdutos();
void menuHead(char titulo[30]);
void opInvalida();
void opcao(char op[30], int num);
int validaEmail(char aux[150]);
void info();
void enderecos();
void addAdress();
void cartoes();
void addCard();
void perfilCliente();
void pagar(int t);
void carrinho();
void printaCardapio(int x);
void restaurantes();
void menuCliente();
void cadastro();
void login();
void tela1();

///========================[MAIN]===============================
int main(){
    copiaClientes();
    copiaProdutos();
    tela1();

    return 0;
}

///--------------CLIENTES------------------
void copiaClientes(){
    FILE*arq;
    arq = fopen("clientes/cadastros.txt", "r");

    char aux[250];
    int linha=0, j=0, i=0, c;

    if(arq == NULL){
        printf("erro ao abrir o arquivo\n");
    }else{

        while(fgets(aux, 250, arq)!=NULL){
            linha++;
            c=0;

            if(linha>2){

                //----CPF------
                j=0;
                while(aux[c]!= ' '){
                    cpf[i][j]=aux[c];
                    c++;
                    j++;
                }
                cpf[i][j]='\0';

                //-----NOME-------
                c=20;
                j=0;
                while(aux[c]!=' ' ||aux[c+1]!='.'){
                    nome[i][j]=aux[c];
                    c++;
                    j++;
                }
                nome[i][j]='\0';

                //----TELEFONE
                j=0;
                for(c=43; c<58; c++){
                    telefone[i][j]=aux[c];
                    j++;
                }
                telefone[i][j]='\0';

                //-----EMAIL------
                j=0;
                c=64;
                while(aux[c]!=' ' ||aux[c+1]!='.'){
                    email[i][j]=aux[c];
                    c++;
                    j++;
                }
                email[i][j]='\0';

                //-----SENHA------
                j=0;
                c=103;
                while(aux[c]!=' ' ||aux[c+1]!='.'){
                    senha[i][j]=aux[c];
                    c++;
                    j++;
                }
                senha[i][j]='\0';

                //-----ENDEREÇO------
                j=0;
                c=122;

                while(aux[c]!=' ' ||aux[c+1]!='.'){
                    endereco[i][0][j]=aux[c];
                    c++;
                    j++;
                }
                endereco[i][0][j]='\0';

                //----CEP------
                j=0;
                for(c=223;c<232; c++){
                    cep[i][0][j]=aux[c];
                    j++;
                }
                cep[i][0][j]='\0';

                i++;
            }
        }
        fclose(arq);
    }
}
///---------------------RESTAURANTE E PRODUTOS----------------------
void copiaProdutos(){
        FILE*arq;
        char tmp[15][50], tmp2[15][100];
        arq = fopen("restaurantes/produtos.txt", "r");

        char aux[200], aux2[15][20];
        int linha =0, j=0, i=0, c;

        if(arq==NULL){
            printf("erro ao abrir o arquivo\n");
        }else{
            while(fgets(aux, 200, arq)!=NULL){
                linha ++;
                c=0;

                if(linha >2){
                    j=0;
                    while(aux[c]!=' ' ||aux[c+1] != '.'){
                        tmp[i][j] =  aux[c];
                        c++;
                        j++;
                    }
                    tmp[i][j]='\0';

                    c=26;
                    j=0;
                    if(aux[28]=='.'){
                            tmp2[i][0]='\0';
                    }else{
                        while(aux[c]!=' ' ||aux[c+1] != '.'){
                            tmp2[i][j] = aux[c];
                            c++;
                            j++;
                        }
                        tmp2[i][j]='\0';
                    }

                    j=0;
                    for(c=99; c<105; c++){
                        if(aux[c]!= '\n'){
                            aux2[i][j]=aux[c];
                            j++;
                        }
                    }
                    aux2[i][j]='\0';
                    i++;
                }
            }
            fclose(arq);
        }

        for(int i=0; i<5; i++){
            strcpy(produto[0][i], tmp[i]);
            strcpy(produto[1][i], tmp[i+5]);
            strcpy(produto[2][i], tmp[i+10]);

            strcpy(desc[0][i], tmp2[i]);
            strcpy(desc[1][i], tmp2[i+5]);
            strcpy(desc[2][i], tmp2[i+10]);

            valor[0][i] = atof(aux2[i]);
            valor[1][i] = atof(aux2[i+5]);
            valor[2][i] = atof(aux2[i+10]);
        }


    }
///---------------------AUXIIARES-------------------------
void menuHead(char titulo[30]){
    int e = strlen(titulo);
    char espaco[30], under[90];

    for(int i = 0; i<e; i++){
        espaco[i]=' ';
    }
    espaco[e]='\0';
    for(int i = 0; i<e*3; i++){
        under[i] = '_';
    }
    under[e*3] = '\0';

    printf("\n %s\n", under);
    printf("|%s%s%s|\n", espaco, espaco, espaco);
    printf("|%s%s%s|\n", espaco, titulo, espaco);
    printf("|%s|\n\n\n", under);
}
void opInvalida(){
    system("cls");
    printf("OPCAO INVALIDA\n\n");
    system("pause");
}
void opcao(char op[30], int num){
    printf("[%d] - %s\n\n", num, op);
}
int validaEmail(char aux[150]){
    int c=0;
    do{
        if(strcmp(aux, email[c])==0 && email[c][0]!='\0'){
            return c;
        }
        c++;
    }while(c<20);
    return -1;
}
///---------------------METODOS DO PROGRAMA-------------------------
void info(){
    system("cls");
    int res;
    menuHead("     Informacoes     ");

    printf("Nome:     %s\n", nome[n]);
    printf("E-mail:   %s\n", email[n]);
    printf("Telefone: %s\n", telefone[n]);
    printf("\n\n_______________________________\n\n");
    opcao("Voltar", 0);
    scanf("%d", &res);

    switch(res){
    case 0:
        break;
    default:
        opInvalida();
        info();
    }
}
void enderecos(){
    system("cls");
    int res;
    menuHead("Enderecos");
    for(int i = 0; i<5; i++){
        if(endereco[n][i][0]!='\0'){
            printf("[%d] - %s\nCEP:%s", i+1, endereco[n][i], cep[n][i]);
            printf("\n____________________________________________\n");
        }
    }
    printf("\n\n");
    opcao("Excluir", 1);
    opcao("Adicionar novo endereco\n", 2);
    opcao("Voltar", 0);
    scanf("%d", &res);
    int i;

    switch(res){
    case 0:
        break;
    case 1:
        printf("Digite o numero do endereco que deseja EXCLUIR: ");
        scanf("%d", &res);
        system ("cls");
        printf("TEM CERTEZA QUE DESEJA EXCLUIR\n");
        printf("%s\nCEP:%s\n\n", endereco[n][res-1], cep[n][res-1]);
        printf("[1] - SIM || [2] - NAO\n");
        do{
            scanf("%d", &i);
            if(i>2 || i<1){
                opInvalida();
            }
        }while(i>2 || i<1);

        switch(i){
        case 1:
            endereco[n][res-1][0]='\0';
            cep[n][res-1][0]='\0';
            printf("\nEndereco apagado com sucesso!\n");
            system("pause");
            for(int i=0; i<9; i++){
                for(int j = i; j<10; j++){
                    if(endereco[n][i][0]=='\0' && endereco[n][j][0]!='\0'){
                        strcpy(endereco[n][i], endereco[n][j]);
                        endereco[n][j][0]='\0';
                    }
                }
            }

            enderecos();
            break;
        case 2:
            enderecos();
            break;
        }
        break;

    case 2:
        addAdress();
        enderecos();
        break;
    default:
        opInvalida();
        enderecos();
    }
}
void addAdress(){
    int i=0;
    while(endereco[n][i][0]!='\0'){
        i++;
    }
    printf("Insira o novo endereco: ");
    fflush(stdin);
    gets(endereco[n][i]);

    printf("Insira o CEP:");
    fflush(stdin);
    gets(cep[n][i]);
    printf("\nEndereco cadastrado com sucesso!\n");
    system("pause");
}
void cartoes(){
    system("cls");
    int res;
    menuHead("Cartoes");
    for(int i = 0; i<5; i++){
        if(cartao[n][i][0]!='\0'){
            printf("[%d] - %s", i+1, cartao[n][i]);
            printf("\n____________________________________________\n");
        }
    }
    printf("\n\n");
    opcao("Excluir", 1);
    opcao("Adicionar novo cartao\n", 2);
    opcao("Voltar", 0);
    scanf("%d", &res);
    int i;

    switch(res){
    case 0:
        break;
    case 1:
        printf("Digite o numero do cartao que deseja EXCLUIR: ");
        scanf("%d", &res);
        system ("cls");
        printf("TEM CERTEZA QUE DESEJA EXCLUIR: ");
        printf("%s\n\n", cartao[n][res-1]);
        printf("[1] - SIM || [2] - NAO\n");
        do{
            scanf("%d", &i);
            if(i>2 || i<1){
                opInvalida();
            }
        }while(i>2 || i<1);

        switch(i){
        case 1:
            cartao[n][res-1][0]='\0';
            printf("\nCartao apagado com sucesso!\n");
            system("pause");
            for(int i=0; i<9; i++){
                for(int j = i; j<10; j++){
                    if(cartao[n][i][0]=='\0' && cartao[n][j][0]!='\0'){
                        strcpy(cartao[n][i], cartao[n][j]);
                        cartao[n][j][0]='\0';
                    }
                }
            }

            cartoes();
            break;
        case 2:
            cartoes();
            break;
        }
        break;

    case 2:
        addCard();
        cartoes();
        break;
    default:
        opInvalida();
        cartoes();
    }
}
void addCard(){
    int i=0;
    while(cartao[n][i][0]!='\0'){
        i++;
    }
    printf("Insira o novo cartao: ");
    fflush(stdin);
    gets(cartao[n][i]);
    printf("\nCartao cadastrado com sucesso!\n");
    system("pause");
}
void perfilCliente(){
    system("cls");
    int res;
    menuHead("     Perfil     ");

    opcao("Informacoes pessoais", 1);
    opcao("Enderecos", 2);
    opcao("Cartoes", 3);
    opcao("Logout\n", 4);
    opcao("Voltar", 0);
    scanf("%d", &res);

    switch(res){
    case 0:
        break;
    case 1:
        info();
        perfilCliente();
        break;
    case 2:
        enderecos();
        perfilCliente();
        break;
    case 3:
        cartoes();
        perfilCliente();
        break;
    case 4:
        tela1();
        break;
    default:
        opInvalida();
        perfilCliente();
    }
}
void pagar(int t){
    system("cls");
    int check=0, check2=0;
    menuHead("Pagamento");

    for(int i = 0; i<5; i++){
        if(endereco[n][i][0]!='\0'){
            printf("[%d] - %s", i+1, endereco[n][i]);
            printf("\n____________________________________________\n");
            check2++;
        }
    }
    int res, k;

    if(check2==0){
        printf("\nNENHUM ENDERECO CADASTRADO\n");
        addAdress();
        k=0;
    }else{
        printf("\nQual endereco deseja usar?\n");
        scanf("%d", &k);
    }


    for(int i = 0; i<5; i++){
        if(cartao[n][i][0]!='\0'){
            printf("[%d] - %s", i+1, cartao[n][i]);
            printf("\n____________________________________________\n");
            check++;
        }
    }
    if(check==0){
        printf("\nNENHUM CARTAO CADASTRADO\n");
        addCard();
        res=0;
    }else{
        printf("\nQual cartao deseja usar?\n");
        scanf("%d", &res);
    }
    printf("\n\nPAGAMENTO REALIZADO!\nSeu pedido chegará entre 40 minutos e 1 hora\nNo endereco: %s\n\n", endereco[n][k]);
    for(int i=0; i<10; i++){
        item[i][0] = '\0';
        total[i]=0.0;
    }
    system("pause");
}
void carrinho(){
    system("cls");
    menuHead("Pagamento");
    int res, i, op=0;
    float tot=0;

    printf("Sua compra foi:\n");
    printf("___________________________________________________\n");
    for(int i=0; i<10; i++){
        if(item[i][0]!='\0'){
            printf("\n[%d] - %-30s R$%-6.2f |\n", i+1, item[i], total[i]);
            tot+=total[i];
        }
    }
    printf("_______________TOTAL: R$%.2f________________\n", tot);

    opcao("Pagar", 1);
    opcao("Excluir item", 2);
    opcao("Voltar", 0);
    scanf("%d", &res);
    switch(res){
    case 0:
        break;
    case 1:
        pagar(tot);
        menuCliente();
        break;
    case 2:     //EXCLUIR ITEM
        if(item[0][0] == '\0'){
            printf("\nNao tem itens para serem excluidos\n");
            system("pause");
            carrinho();
        }else{
            printf("Digite o numero do item que deseja EXCLUIR: ");
            scanf("%d", &op);
            system ("cls");
            printf("TEM CERTEZA QUE DESEJA EXCLUIR\n");
            printf("%s\n\n", item[op-1]);
            printf("[1] - SIM || [2] - NAO\n");
            do{
                scanf("%d", &i);
                if(i>2 || i<1){
                    opInvalida();
                }
            }while(i>2 || i<1);

            switch(i){
            case 1:
                item[op-1][0]='\0';
                total[op-1]=0.0;
                printf("\nItem apagado com sucesso!\n");
                system("pause");

                for(int i=0; i<9; i++){
                    for(int j = i; j<10; j++){
                        if(item[i][0]=='\0' && item[j][0]!='\0'){
                            strcpy(item[i], item[j]);
                            item[j][0]='\0';
                            total[i]=total[j];
                            total[j]=0.0;
                        }
                    }
                }
                carrinho();
                break;
            case 2:
                carrinho();
                break;
            }
        }
        break;
    default:
        opInvalida();
        carrinho();
    }
}
void printaCardapio(int x){
    system("cls");
    menuHead(restaurante[x]);

    printf("\nO que deseja adicionar ao carrinho?\n");
    for(int i=0; i<5; i++){
            printf("\n[%d] - %-30s R$%.2f\n%s", i+1, produto[x][i], valor[x][i], desc[x][i]);
            printf("\n________________________________________________\n");
    }
    opcao("Voltar", 0);
    int res, c=0;
    scanf("%d", &res);
    while(res>5 || res<0){
        opInvalida();
        printaCardapio(x);
    }
    res-=1;
    switch(res){
    case -1:
        break;
    default:
        while(item[c][0]!='\0'){
            c++;
        }
        strcpy(item[c], produto[x][res]);
        total[c]=valor[x][res];
        system("cls");
        printf("Voce adicionou: %s a sacola\nDeseja adicionar mais itens?\n [1] - SIM || [2] - NAO\n", produto[x][res]);
        scanf("%d", &res);

        switch(res){
        case 1:
            printaCardapio(x);
            break;
        case 2:
            carrinho();
            printaCardapio(x);
            break;
        default:
            opInvalida();
            printaCardapio(x);
        }
    }
}
void restaurantes(){
    system("cls");
    menuHead("   Restaurantes   ");
    int res;

    for(int i=0; i<3; i++){
            opcao(restaurante[i], i+1);
            printf("____________________________________________\n");
    }
    printf("\n[0] - Voltar\n\n");
    scanf("%d", &res);
    while(res>3 || res<=-1){
        opInvalida();
        restaurantes();
    }
    res-=1;

    switch(res){
    case -1:
        break;
    default:
        printaCardapio(res);
        restaurantes();
    }
}
void menuCliente(){

    system("cls");
    int res;
    menuHead("     Ai Qui Dilica     ");

    opcao("Restaurantes", 1);
    opcao("Carrinho", 2);
    opcao("Perfil", 3);
    scanf("%d", &res);

    switch(res){
    case 1:
        restaurantes();
        menuCliente();
        break;
    case 2:
        carrinho();
        menuCliente();
        break;
    case 3:
        perfilCliente();
        menuCliente();
        break;
    default:
        opInvalida();
        menuCliente();
    }
}
void cadastro(){
    system("cls");
    char aux[150];
    int i=0;

    while(email[i][0]!='\0'){
        i++;
    }

    do{
        system("cls");
        menuHead("   CADASTRO   ");
        printf("Insira seu email: ");
        fflush(stdin);
        gets(aux);
        if(validaEmail(aux)!=-1){
            printf("\nEmail já cadastrado\n\n");
        }
    }while(validaEmail(aux)!=-1);
    strcpy(email[i], aux);
        do{
            printf("Confirme seu email: ");
            fflush(stdin);
            gets(aux);
            if(strcmp(aux, email[i])!=0){
                printf("\n\nOs emails nao sao iguais!\n\n");
                system("pause");
            }
        }while(strcmp(aux, email[i])!=0);

    do{
        printf("Insira uma senha: ");
        fflush(stdin);
        gets(senha[i]);

        system("cls");
        menuHead("   CADASTRO   ");
        printf("Confirme sua senha: ");
        fflush(stdin);
        gets(aux);
        if(strcmp(aux, senha[i])!=0){
            printf("\n\nAs senhas nao sao iguais!\n\n");
            system("pause");
        }
    }while(strcmp(aux, senha[i])!=0);
    printf("Um E-mail de confirmação foi enviado para: %s", email[i]);

    tela1();
}
void login(){
    char aux[150];
    char aux2[50];
    int em, res=-1;

    system("cls");
    menuHead("     LOGIN     ");

    fflush(stdin);
    printf("EMAIL: ");
    gets(aux);
    em=validaEmail(aux);
    if(em==-1){
        system("cls");
        printf("Email nao cadastrado\n\n");
        system("pause");
    }else{
        do{
            fflush(stdin);
            printf("SENHA: ");
            gets(aux2);
            if(strcmp(aux2, senha[em])!=0){
                printf("Senha incorreta!\n\n");
                system("pause");
            }
        }while(strcmp(aux2, senha[em])!=0);
        n=em;
        menuCliente();
    }

}
void tela1(){

    for(int i=0; i<10; i++){
        item[i][0] = '\0';
        total[i]=0.0;
    }

    system("cls");
    int res;
    menuHead("     Ai Qui Dilica      ");

    opcao("fazer login", 1);
    opcao("criar conta", 2);
    scanf("%d", &res);
    switch(res){
    case 1:
        login();
        tela1();
        break;
    case 2:
        cadastro();
        break;
    default:
        opInvalida();
        tela1();
    }
}


