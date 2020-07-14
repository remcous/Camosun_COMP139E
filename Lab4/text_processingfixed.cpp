#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
    string word;
    int num, total;
    char c;

    try{
        // Ensures that the read and write file names are entered on the command line
        if(argc != 3){
            throw "Invalid usage, example: ./text_processing textAndNumbers.txt results.txt";
        }

        // Prepares the input file for use in the program, closes if the file could not be opened
        ifstream read_file(argv[1]);
        if(!read_file){
            throw "Input file could not be opened.";
        }

        // Prepares the output file for use in the program, closes if the file could not be opened
        ofstream write_file(argv[2], ios::app);
        if(!write_file){
            throw "Output file could not be opened.";
        }

        while(!read_file.eof()){
            // Checks the next character in the read_file
            c = read_file.peek();

            // Ensures that the peek did not encounter the end of file
            if(read_file.eof()){
                continue;
            }
            
            // If the peeked character is a digit, get the number
            if(c>='0' && c<='9'){
                total = read_file.get() - '0';

                c = read_file.peek();

                while(c>='0' && c<='9'){
                    num = read_file.get();
                    c = read_file.peek();
                    total = total * 10 + num - '0';
                }

                // Outputs the complete integer to the output file
                write_file << "Found an integer: " << total << endl;
            } // Handles characters which are not white space or digits
            else if(c!=' '&&c!='\n'){
                word = read_file.get();

                c = read_file.peek();

                while(c!=' ' && (c<'0'||c>'9') && c!='\n' && !read_file.eof()){
                    word.push_back(read_file.get());
                    c = read_file.peek();
                }

                // Outputs the complete word to the output file
                write_file << "Found a " << word.length() << " character word: " << word << endl;
            } // white space or next lines are ignored
            else{
                read_file.ignore();
            }
        }

        // Closes the files,
        read_file.close();
        write_file.close();
    }
    catch(char const* msg){
        cerr << msg << endl;
    }

    return 0;
}