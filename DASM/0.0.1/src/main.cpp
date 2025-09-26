#include <string>
#include <cstring>
#include <iostream>

#define print(x) std::cout<<(x)<<std::endl
#define printn(x) std::cout<<(x)

#include "../include/AAcode_gen.hpp"
// #include "../include/code_structs.hpp"
// #include "../include/errs.hpp"
// #include "../include/lexer.hpp"
// #include "../include/parser.hpp"
// #include "../include/preproc.hpp"
// #include "../include/utils.hpp"
// #include "../include/utils2.hpp"
// #include "../include/utils3.hpp"
// #include "../include/utils4.hpp"


int main(int argc, char* argv[]){
    if(argc == 1){
        print("dasm -help");
    }
    else if(argc == 2){
        if(strcmp(argv[1], "-help") == 0){
            print("all commands:");
            print("    dasm -version");
            print("    dasm -info");
            print("    dasm -assemble \"<input.asm>\" \"<output.obj>\"");
            print("    dasm -showcm \"<input.asm>\"");
            print("    dasm -debug \"<input.asm>\"");
        }
        else if(strcmp(argv[1], "-version")){
            print("0.0.1");
        }
        else if(strcmp(argv[1], "-info")==0){
            print("developed by Mohsen Tavassoli in 2025");
            print("created with c++(mingw).");
            print("mail : mhsntvssl@gmail.com");
        }
        else{
            printn("unknown command : ");
            printn(argv[1]);
        }
    }
    else if(argc == 3){
        if(strcmp(argv[1], "-showcm")){

        }
        else if(strcmp(argv[1], "-debug")){

        }
        else{
            printn("unknown command : ");
            printn(argv[1]);
        }
    }
    else if(argc == 4){
        if(strcmp(argv[1], "-assemble")==0){
            ASSEMBLE(argv[2], argv[3]);
        }
        else{
            printn("unknown command :");
            print(argv[1]);
        }
    }
    else{
        print("unknown commmands :");
        for(int i = 0; i < argc; ++i){
            print(argv[i]);
        }
    }
    return 0;
}