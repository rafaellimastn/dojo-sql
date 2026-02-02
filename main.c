#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const long BUFFER_SIZE = 1000;
const int NUMBER_CITIES = 10;
void clear_array(char *array, int size);

typedef struct {
    char *city;
    int counter;
} city_counter;

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    city_counter cities[NUMBER_CITIES];

    FILE *read_file = fopen("ignore/cidades.txt", "r");
    if (read_file == NULL) {
        perror("Erro ao abrir o arquivo de leitura.");
        return 1;
    }
    
    // ler uma linha e comparar se a cidade esta ou nao no array
    size_t bytes_read;
    int current, first; current = first = 0;
    char current_string[20];
    
    bytes_read = fread(buffer, 1, BUFFER_SIZE, read_file);
    for (int j = 0; j < NUMBER_CITIES; j++) {
        int i = 0;
        clear_array(current_string, 20);
        while(buffer[current] != '\n') {
            if(current > bytes_read) {
                break;
            }
            // passar o valor da linha para o array

            current_string[i] = buffer[current];
            i++;
            current++;
        }
        strcpy(cities[j].city, current_string);
        printf("Cidade %d: %s\n", (j + 1) , cities[j].city); 
        current++;
    }

    // se estiver: some um ao contador dessa cidade

    // se nao: adicione a cidade ao array e crie um contador p esta cidade

    return 0;
}

void clear_array(char *array, int size) {
    for (int i = 0;  i < size; i++)  {
        array[i] = 0;
    }
}