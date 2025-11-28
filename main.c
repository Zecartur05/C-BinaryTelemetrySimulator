#include <stdio.h>
#include <stdint.h>


#define TempBits 7
#define BateriaBits 4
#define Erro 1

struct  informacao
{
    uint16_t info;
}INFORMACAO;

void lerFicheiro(){
    
}

void guardarficheiro(struct informacao data){
    FILE *f;
    f = fopen("telemetria.bin","wb");
    if (f == NULL) {
        printf("Erro ao abrir o ficheiro\n");
        return;
    }
    fwrite(&data, sizeof(struct informacao), 1, f);
    fclose(f);
}

void guardardados(){
    struct informacao data;
    int temp,bat,err;
    do{
        printf("Temperatura(entre 0 e 100)");
        scanf("%d",&temp);
    }while(temp < 0 || temp > 100);
    do{
        printf("Bateria(entre 0 e 15)");
        scanf("%d",&bat);
    }while(bat < 0 || bat > 15);
    do{
        printf("Erro(entre 0 e 1)");
        scanf("%d",&err);
    }while(err < 0 || err > 1);
    
    data.info = temp;
    data.info = data.info << BateriaBits;
    data.info = data.info | bat;
    data.info = data.info << Erro;
    data.info = data.info | err;
    printf("Valor Final: %d\n",data.info);
    guardarficheiro(data);
    printf("--------------------\n");
    printf("valor Erro:%d\n",data.info & Erro);
    printf("valor Bateria:%d\n",data.info>>Erro & 0x0F);
    printf("valor Temperatura:%d\n",(data.info>> (Erro + BateriaBits)) & 0x7F);


}


void menu(){
    printf("------------------------\n");
    printf("1 - Guardar Dados\n");
    printf("2 - Ler Dados Printar\n");
    printf("9 - Quit\n");
    printf("------------------------\n");
}

int main(){
    int op = 0;
    do{
        menu();
        scanf("%d",&op);
        switch (op){
        case 1:
            guardardados();
            break;
        case 2:
            lerFicheiro();
            break;
        case 9:
            break;
        default:
            break;
        }
    }while(op!=9);
    return 0;
}