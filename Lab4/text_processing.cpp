#include <iostream>
#include <fstream>
#include <string>

using namespace std;
static const int MAX_LINE = 256;

int main(int argc, char *argv[]){
    int num, start, num_chars;
    string word, line;

    // Ensures that the read and write file names are entered on the command line
    if(argc != 3){
        cerr << "Invalid usage, example: ./text_processing textAndNumbers.txt results.txt" << endl;
        return 0;
    }

    // Prepares the input file for use in the program, closes if the file could not be opened
    ifstream read_file(argv[1]);
    if(!read_file){
        cerr << "File " << argv[1] << " could not be opened!" << endl;
        return 0;
    }

    // Prepares the output file for use in the program, closes if the file could not be opened
    ofstream write_file(argv[2], ios::app);
    if(!write_file){
        cerr << "File " << argv[2] << " could not be opened!" << endl;
        return 0;
    }

    // Loops through the file, ensuring that eof has not been reached
    while(read_file){
        // Inputs a line from the input file and stores it in string line
        getline(read_file, line);

        // Loop to parse the data contained within the current line
        for(int i=0; line[i]!='\0'; i++){
            // Checks for a number in the current index character in the line
            if(line[i]>='0' && line[i]<='9'){
                // Stores the most significant digit in num
                num = line[i] - '0';

                // Checks if there is a numerical digit in the following index
                while(line[i+1]>='0'&&line[i+1]<='9' && line[i+1]!='\0'){
                    i++;

                    // adds the new digit to the previous integer as the new least significant digit
                    num *= 10;
                    num += line[i] - '0';
                }

                // Outputs the complete integer to the output file
                write_file << "Found an integer: " << num << endl;
            }   // Checks for alphabetic characters at current index in the line
            else if (line[i]!=' '){
                // Stores the starting index of the word
                start = i;

                // Checks for alphabetic characters in the following index until the end of the word
                while(line[i+1]!=' ' && (line[i+1]<'0'||line[i+1]>'9') && line[i+1]!='\0'){
                    i++;
                }

                // Gets the word as a substring of line using the starting index and the number of characters
                num_chars = i + 1 - start;
                word = line.substr(start, num_chars);

                // Outputs the complete word to the output file
                write_file << "Found a " << num_chars << " character word: " << word << endl;
            }
        }
    }

    read_file.close();
    write_file.close();

    return 0;
}