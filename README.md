# File Encryption/Decryption Tool

A lightweight command-line tool to encrypt and decrypt files using XOR-based encryption with a custom key. Supports both text and binary files, ensuring secure and reversible data transformation.

## Project Structure

The project follows a simple, modular structure with clear separation of concerns. Below are the **initial files** (included in the project repository) and **generated files** (created after running the tool):

### Initial Files (Repository Contents)



```
encryto_demo/

├── encrypt.c        # Core implementation (file I/O, encryption/decryption logic)

├── encrypt.h        # Header file (function declarations, enum definitions)

├── test.c           # Main function (command-line argument parsing, mode handling)

├── Makefile         # Compilation script (build/clean targets)

└── README.md        # Documentation (usage, installation, examples)
```

### Generated Files (Created After Use)

These files are automatically generated when you run the tool—they are not part of the initial project structure:



| File            | Description                                                                                   |
| --------------- | --------------------------------------------------------------------------------------------- |
| `test.txt`      | Optional example input file (you can use any file as input; create manually or use your own). |
| `encrypted.txt` | Output of encryption (`-e` mode): Binary file containing encrypted data.                      |
| `decrypted.txt` | Output of decryption (`-d` mode): Restored original file (matches input).                     |

### File Roles (Initial Files)



| File        | Purpose                                                                                                                         |
| ----------- | ------------------------------------------------------------------------------------------------------------------------------- |
| `encrypt.c` | Implements core functions: `read_file()`, `print_file()`, `save_to_file()`, `encrypto_file()`, `decrypto_file()`, `get_mode()`. |
| `encrypt.h` | Declares functions, defines the `Mode` enum (ENCRYPTO/DECRYPTO/UNKOWN), and includes required headers.                          |
| `test.c`    | Contains the `main()` function: parses command-line arguments, triggers mode-specific logic, and manages memory.                |
| `Makefile`  | Automates compilation: builds the `encrypto_demo` executable and cleans intermediate files.                                     |
| `README.md` | Comprehensive documentation for installation, usage, and troubleshooting.                                                       |

## Features



* **Custom Key Support**: Use your own secret key for encryption/decryption (key is required for both operations).

* **Dual Mode**: Switch between encryption (`-e`) and decryption (`-d`) modes easily.

* **Binary Compatibility**: Works with all file types (text, images, executables, etc.) by handling raw binary data.

* **Cross-Platform**: Compatible with Linux, macOS, and Windows (with GCC or compatible compiler).

## Prerequisites



* A C compiler (e.g., GCC, Clang)

* Make (for easy compilation)

## Installation



1. Clone or download the project to your local machine:



```
git clone git@github.com:liboxin-cloud/A-light-file-encryptor-in-C.git

cd encryto_demo
```



1. Compile the source code using Make:



```
make
```



1. The executable `encrypto_demo` will be generated in the project directory.

## Usage

### Basic Syntax



```
./encrypto_demo <mode> <file_path> 
```

### Mode Options



| Mode | Description             |
| ---- | ----------------------- |
| `-e` | Encrypt the target file |
| `-d` | Decrypt the target file |

### Required Parameters



* `<mode>`: Must be either `-e` (encrypt) or `-d` (decrypt).

* `<file_path>`: Full or relative path to the file you want to process (e.g., `myfile.txt`, `images/photo.jpg`).

* `<your own key>`: Your custom secret key (case-sensitive, any length—longer keys are more secure).

## Examples

### 1. Encrypt a File

First, create or use an input file (e.g., `test.txt` with content `hello world!!!`). Then encrypt it with the key `mysecretkey`:



```
./encrypto_demo -e test.txt mysecretkey
```

Output:



```
Original content:

hello world!!!

encrypto success

After encryption:

[encrypted content (may include invisible binary characters)]

the file write success
```

This generates `encrypted.txt` in the project directory.

### 2. Decrypt a File

Use the same key to decrypt `encrypted.txt` (generated in the previous step):



```
./encrypto_demo -d encrypted.txt mysecretkey
```

Output:



```
Original content:

[encrypted content]

decrypto success

After decryption:

hello world!!!

the file write success
```

This generates `decrypted.txt` (restored original file).

## File Output Details



* **Encryption**: `encrypted.txt` is a binary file—do not edit or modify it manually (invisible characters may cause corruption).

* **Decryption**: `decrypted.txt` is an exact copy of the original input file (rename it if needed, e.g., `decrypted.txt` → `restored_photo.jpg` for binary files).

> ⚠️ Note: The tool never overwrites your original input file—encrypted/decrypted data is saved to separate files for safety.

## Encryption Logic

The tool uses a secure XOR-based algorithm with two layers of obfuscation to prevent predictable patterns:



```
buffer[i] ^= key[i % key_len] ^ i;
```



* `key[i % key_len]`: Cycles through your custom key to match the length of the input file (ensures the key is reused without repetition).

* `i`: Adds index-based variation (each character is encrypted with a unique combination of key and position).

* **Reversibility**: XOR is its own inverse—applying the same operation twice (with the same key) restores the original data.

## Notes



* **Key Security**: Your secret key is never stored or logged—keep it safe! Losing the key means permanent data loss (no way to recover encrypted files).

* **Input Flexibility**: You can use any file as input (not just `test.txt`). For example, encrypt a photo: `./encrypto_demo -e vacation.jpg mykey123`.

* **Binary Files**: Decrypted binary files (e.g., images, executables) will have a `.txt` extension—rename them to their original extension to use them (e.g., `decrypted.txt` → `vacation.jpg`).

## Clean Up

To remove the executable, object files, and generated files:



```
# Remove compiled files (executable + .o files)

make clean

# Optional: Remove generated encrypted/decrypted files

rm -f encrypted.txt decrypted.txt
```

## Troubleshooting

### Common Errors



1. **"file open failed"**:

* Check if the input file path is correct (use `pwd` to verify your current directory).

* Ensure the file exists and you have read permissions.

1. **"buffer malloc failed"**:

* The input file is too large for available system memory—try smaller files or free up memory.

1. **Decryption returns garbled text**:

* Ensure you’re using the **exact same key** (case-sensitive) as encryption.

* Verify you’re decrypting `encrypted.txt` (not the original input file).

1. **Compilation errors**:

* Ensure GCC and Make are installed (run `gcc --version` and `make --version` to check).

* Confirm all initial files (`encrypt.c`, `encrypt.h`, `test.c`, `Makefile`) are present in the project directory.

## License

This project is licensed under the MIT License. Feel free to use, modify, and distribute it as needed. See the `LICENSE` file for full details (add a `LICENSE` file to your repository for completeness).

author's email:335183250@qq.com

***

