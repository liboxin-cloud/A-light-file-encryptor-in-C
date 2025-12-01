#ifndef __ENCRYPTO_H__
#define __ENCRYPTO_H__
#define BUFFER_MAX_SIZE 1024
#include <stddef.h>

typedef enum Mode {
    ENCRYPTO,
    DECRYPTO,
    UNKOWN
}Mode;

char* read_file(const char* file_path, size_t* file_size);

void print_file(const char* buffer, size_t file_size);

void save_to_file(const char* buffer, size_t file_size, const char* file_name);

void encrypto_file(char* buffer, size_t file_size,const char* key);

void decrypto_file(char* buffer, size_t file_size,const char* key);

Mode get_mode(const char* mode);

#endif
