#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Nieprawidlowa ilosc argumentow!\n");
        return 22;
    }

    DIR* source = opendir(argv[1]);
    mkdir(argv[2], S_IRWXU|S_IRGRP|S_IROTH);
    DIR* destination = opendir(argv[2]);

    if (source == NULL || destination == NULL) printf("Nie udalo sie otworzyc folderow\n");

    struct dirent* current_file;

    while (current_file = readdir(source), current_file != NULL) {
        if (strcmp(".", current_file->d_name) == 0 || 
            strcmp("..", current_file->d_name) == 0 ||
            (strlen(current_file->d_name) >= 4 && strcmp(&current_file->d_name[strlen(current_file->d_name) - 4], ".txt"))) continue;

        char *path_to_file = malloc(PATH_MAX + 1);
        char *path_to_output = malloc(PATH_MAX + 1);
        
        strcpy(path_to_file, argv[1]);
        strcat(path_to_file, "/\0");
        strncat(path_to_file, current_file->d_name, strlen(current_file->d_name));

        strcpy(path_to_output, argv[2]);
        strcat(path_to_output, "/\0");
        strncat(path_to_output, current_file->d_name, strlen(current_file->d_name));

        FILE *source_file = fopen(path_to_file, "r");
        FILE *destination_file = fopen(path_to_output, "w");

        if (source_file == NULL) printf("Blad w otwarciu zrodla\n");
        if (destination_file == NULL) printf("Blad w otwarciu celu\n");

        char *line = NULL;
        size_t length = 0;
        ssize_t read;
        ssize_t start;

        while ((read = getline(&line, &length, source_file)) != -1) {
            if (strcmp(&line[read - 1], "\n") == 0) start = read - 2;
            else start = read - 1;

            for (int i = start; i >= 0; i--) {
                char *current_char = &line[i];
                fwrite(current_char, 1, 1, destination_file);
            }

            if (start == read - 2) fwrite("\n", 1, 1, destination_file);
        }

        fclose(source_file);
        fclose(destination_file);

        free(path_to_file);
        free(path_to_output);
    }

    closedir(source);
    closedir(destination);
}