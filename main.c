#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void write();
char * cleanphrase(char phrase[]);
char * readFile(char nameFile[]);
void date();
void menu();
int submenu();
void playfair(int);
void vigenere(int);
void trans(int);

int main() {
    menu();
    return 0;
}

void date(){
    time_t t;
    struct tm *tm;
    t = time(NULL);
    tm = localtime(&t);
    printf("\t\t\t%02d-%02d-%02d\n", tm->tm_mday, tm->tm_mon, 1900+tm->tm_year);
    printf("\tBaeza Ramirez Luis Gerardo 2012010273\n");
    printf("\tSeleccione una Pocion\n");
}

void menu(){
    char valref;
    int valor;
    do{
        system("cls");
        date();
        printf("1.Introducir texto a cifrar\n2.Cifrado Playfair\n3.Cifrado Vigenere\n4.Transposicion con clave\n5.Salir\n");
        scanf("%c",&valref);

        switch(valref){
            case '1':
                write();
                break;
            case '2':
                valor = submenu();
                (valor == 0)?:playfair(valor);
                break;
            case '3':
                valor = submenu();
                (valor == 0)?:vigenere(valor);
                break;
            case '4':
                valor = submenu();
                (valor == 0)?:trans(valor);
                break;
            case '5':
                printf("Adios");
                break;
            default:
                printf("invalid");
                break;
        }
    }while(valref != '5');

}

int submenu(){
    char valref;
    int returnvalue;
    do{
        system("cls");
        date();
        printf("1.Cifrar texto\n2.Ver texto cifrado\n3.Descifrar texto\n4.Regresar\n");
        fflush(stdin);
        scanf("%c", &valref);
        returnvalue = valref - '0';
        switch(returnvalue){
            case 1 || 2 || 3:
                return returnvalue;
            case 4:
                printf("Adios");
                returnvalue = 0;
                break;
            default:
                printf("invalid");
                break;
        }
    }while(valref != '4');    
}

char * cleanphrase(char phrase[]){
    int i = 0;
    while(i <= 1024){
        if(phrase[i] == '\n'){
            phrase[i] = '\0';
        }
        i++;
    }
    return phrase;
}

void write() {
    FILE *file;
    char phrase[1024];

    file = fopen("Textoacifrar.txt", "w+");
    if (file == NULL){
        printf("No se ha podido abrir el archivo.\n");
        exit(1);
    }
    printf("Introduce el mensaje a cifrar\n");
    fflush(stdin);
    fgets(phrase,1024,stdin);
    char *ph = cleanphrase(phrase);
    fprintf(file,"%s", ph);
    fclose(file);
    system("pause");
}

char * readFile(char nameFile[20]){
    FILE * file = fopen(nameFile, "rb");
    char texto[1024];
    if(file == NULL){
        perror("Archivo no encontrado");
    }

    while (feof(file) == 0){
        fgets(texto, sizeof(texto), file);
    }
    fclose(file);    
    return texto;
}

void playfair(int valref){
    char * lectura;
    FILE * file = fopen("Textoacifrar.txt", "rb");
    char texto[1024];
    char mat[5][5] = {{'T', 'H', 'U', 'N', 'D'},
                      {'P', 'A', 'S', 'Z', 'E'},
                      {'B', 'O', 'L', '/', 'R'},
                      {'G', 'X', 'V', 'C', 'F'},
                      {'K', 'M', 'W', 'Y', 'Q'}};
    switch(valref){
        case 1:
            if(file == NULL){
                perror("Archivo no encontrado");
            }

            while (feof(file) == 0){
                fgets(texto, sizeof(texto), file);
            }
            fclose(file);
            char *cifrado;
            int i = 0;

            while(i<= strlen(lectura)){
                fflush(cifrado[i]);
                printf("ciclo %i, valores %c, %c \n", i, lectura[i], lectura[i+1]);
                if (i == 0){
                    if (lectura[i] != lectura[i+1]){
                        cifrado[i] = lectura[i];
                        printf("%s", cifrado);
                    }
                    if (lectura[i] == lectura[i+1]){
                        cifrado[i] = lectura[i];
                        cifrado[strlen(cifrado)] = 'x';
                    }
                } else if (lectura[i] == lectura[i+1]){
                    cifrado[strlen(cifrado)] = lectura[i];
                    cifrado[strlen(cifrado)] = 'x';
                } else{
                    cifrado[strlen(cifrado)] = lectura[i];
                }
                i++;
                printf("%c\n", lectura[i]);
                printf("Valores guardados %s \n", cifrado);
                system("pause");
            }
            printf("Palabra final: %s", cifrado);
            //(strlen(cifrado) % 2 == 0)

            system("pause");
            break;
        case 2:
            lectura = readFile("TextoPlayfair.txt");
            break;
        case 3:
            lectura = readFile("TextoPlayfair.txt");
            break;
    }
}

void vigenere(int valref){

}

void trans(int valref){

}
