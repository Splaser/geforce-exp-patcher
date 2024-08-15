#include <iostream>
#include <fstream>
#include <regex>
#include <filesystem>
#include <windows.h>

using namespace std;

bool is_file_exists(const std::filesystem::path& path) {
    return exists(path);
}

int main() {
    cout << "===GFE Patcher===" << '\n';

    std::filesystem::path appjs = R"(C:\Program Files\NVIDIA Corporation\NVIDIA GeForce Experience\www\app.js)";
    cout << "Trying to find app.js in " << appjs.string() << '\n';

    while (!is_file_exists(appjs)) {
        cout << "Cannot find app.js at the specified location." << '\n';
        cout << "Please enter a valid path or type 'exit' to quit:" << '\n';
        if (appjs.string() == "exit") {
            return 0;
        }
    }

    try {
        ifstream in_file(appjs);
        if (!in_file) {
            throw runtime_error("Error opening input file.");
        }

        istreambuf_iterator file_begin(in_file);
        istreambuf_iterator<char> file_end;
        string rawjs(file_begin, file_end);
        in_file.close();

        regex reg_match(R"("choose"===\w\.nvActiveAuthView[\D]*\)\})");

        if (smatch res; !regex_search(rawjs, res, reg_match)) {
            cout << "No match found in the file." << '\n';
            system("pause > nul");
            return 0;
        }
        std::string replacement = R"("choose"===this.nvActiveAuthView)};this.handleLoggedIn({sessionToken:"",userToken:"",user: {core:{displayName:"GFE",primaryEmailVerified: true}}});)";

        rawjs = regex_replace(rawjs, reg_match, replacement);
        ofstream out_file(appjs, ios::out);
        if (!out_file) {
            throw runtime_error("Failed to write to the file, maybe no permission.");
        }
        out_file << rawjs;
        out_file.close();
        cout << "Succeed" << '\n';

    }
    catch (const exception& e) {
        cout << e.what() << '\n';
        system("pause > nul");
        return 1;
    }

    system("pause > nul");
    return 0;
}
