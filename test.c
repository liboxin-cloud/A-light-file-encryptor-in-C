#include "encrypt.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    if (argc != 4) {
        fprintf(stderr, "Usage: \n");
        fprintf(stderr, "encrypto.exe -e <your file path> <your own key> => to encrypto your file\n");
        fprintf(stderr, "encrypto.exe -d <your file path> <your own key> => to decrypto your file\n");
        return 1;
    }

    char* mode = argv[1];
    char* key = argv[3];
    char* file_path = argv[2];


    size_t file_size = 0;
    char* buffer = read_file(file_path, &file_size);
    if (!buffer) {
        return 1;
    }


    printf("Original content:\n");
    print_file(buffer, file_size);

    switch (get_mode(mode))
    {
    case DECRYPTO: {
        decrypto_file(buffer, file_size, key);

        printf("\nAfter decryption:\n");
        print_file(buffer, file_size);

        save_to_file(buffer, file_size, "decrypted");
        break;
    }
    case ENCRYPTO: {
        encrypto_file(buffer, file_size, key);
        printf("\nAfter encryption:\n");
        print_file(buffer, file_size);

        save_to_file(buffer, file_size, "encrypted");
        break;
    }
    case UNKOWN: {
        fprintf(stderr, "ERROR: UNKOWN TYPE\n");
        break;
    }
    default:
        break;
    }

    free(buffer);
    return 0;
}
