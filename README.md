
# GFE Patcher

### Description
**GFE Patcher** is a small utility program written in C++ designed to modify the `app.js` file of NVIDIA GeForce Experience. The program replaces a specific piece of code in `app.js` with a custom string that simulates a successful login, bypassing the usual login requirements.

### Features
- **File Path Validation**: The program checks if the `app.js` file exists at the specified location.
- **Regex Matching & Replacement**: Utilizes regular expressions to find and replace specific patterns in the `app.js` file.
- **Error Handling**: Handles common file I/O errors, such as missing files or permission issues.

### Prerequisites
- **Windows OS**: The program uses Windows-specific headers (`<windows.h>`), making it incompatible with other operating systems.
- **C++ Compiler**: A C++ compiler that supports C++17 or later is required to compile the program.
- **NVIDIA GeForce Experience**: This program is specifically designed for NVIDIA GeForce Experience. You should have it installed on your system.

### How to Use

1. **Clone the Repository**:
    ```sh
    git clone https://github.com/yourusername/gfe-patcher.git
    cd gfe-patcher
    ```

2. **Build the Program**:
   Use your preferred C++ compiler to build the program. Below is an example using `g++`:
    ```sh
    g++ -o GFE_Patcher main.cpp -lstdc++fs
    ```

3. **Run the Program**:
    Execute the built binary:
    ```sh
    ./GFE_Patcher
    ```
    - The program will try to locate `app.js` in the default installation directory: `C:\Program Files\NVIDIA Corporation\NVIDIA GeForce Experience\www\app.js`.
    - If the file is not found, you'll be prompted to enter the correct path or type `exit` to quit the program.

4. **Result**:
    - If the specified pattern is found in `app.js`, it will be replaced with the custom string, and the program will display "Succeed".
    - If no match is found, or there is an error, the program will notify you.

### Error Handling
- **File Not Found**: If `app.js` is not found at the specified location, the program will prompt you to enter a correct path or exit.
- **File Open Error**: If there is an issue opening `app.js`, the program will terminate with an error message.
- **Write Permission Error**: If the program cannot write to `app.js`, it will display an error indicating a possible permission issue.

### Disclaimer
This program modifies system files related to NVIDIA GeForce Experience. Use it at your own risk. Ensure you have backups of your files before running this patcher.

### License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

### Contact
If you have any questions or issues, feel free to open an issue on the repository or contact me directly.
