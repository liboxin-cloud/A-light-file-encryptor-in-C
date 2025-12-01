#include "encrypt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* read_file(const char* file_path, size_t* file_size) {
    FILE* fp = fopen(file_path, "rb");

    if (NULL == fp) {
        fprintf(stderr, "file open failed, file path is %s\n", file_path);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    *file_size = (size_t)ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* buffer = (char*)malloc(sizeof(char) * (*file_size));

    if (NULL == buffer) {
        fprintf(stderr, "buffer malloc failed\n");
        fclose(fp);
        return NULL;
    }

    fread(buffer, 1, *file_size, fp);
    fclose(fp);
    return buffer;
}

void print_file(const char* buffer, size_t file_size) {
    if (NULL == buffer) {
        fprintf(stderr, "the buffer is NULL\n");
        return;
    }


    for (size_t i = 0;i < file_size;i++) {
        printf("%c", buffer[i]);
    }

    printf("\n");
}

void save_to_file(const char* buffer, size_t file_size, const char* file_name) {
    if (NULL == buffer) {
        fprintf(stderr, "the buffer is NULL\n");
        return;
    }

    FILE* fp = fopen(file_name, "wb");

    if (NULL == fp) {
        fprintf(stderr, "fp is NULL\n");
        return;
    }

    fwrite(buffer, 1, file_size, fp);

    printf("the file write success\n");
    fclose(fp);

}

void encrypto_file(char* buffer, size_t file_size, const char* key) {
    if (NULL == buffer) {
        fprintf(stderr, "buffer is NULL\n");
        return;
    }

    size_t key_len = strlen(key);

    for (size_t i = 0;i < file_size;i++) {
        buffer[i] ^= key[i % key_len] ^ i;
    }

    printf("encrypto success\n");

}

void decrypto_file(char* buffer, size_t file_size, const char* key) {
    if (NULL == buffer) {
        fprintf(stderr, "buffer is NULL\n");
        return;
    }

    size_t key_len = strlen(key);

    for (size_t i = 0;i < file_size;i++) {
        buffer[i] ^= key[i % key_len] ^ i;
    }

    printf("decrypto success\n");
}

Mode get_mode(const char* mode) {
    if (NULL == mode) {
        fprintf(stderr, "the mode is NULL\n");
        return UNKOWN;
    }

    if (strcmp(mode, "-e") == 0) {
        return ENCRYPTO;
    } else if (strcmp(mode, "-d") == 0) {
        return DECRYPTO;
    } else {
        return UNKOWN;
    }

    return UNKOWN;
}