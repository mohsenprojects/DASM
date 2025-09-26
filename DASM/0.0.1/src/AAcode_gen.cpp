#include "../include/AAcode_gen.hpp"


void ASSEMBLE(std::string IFILE, std::string OFILE){
// *******************************************reading the file*******************************************

    std::vector<std::string> code_lines = F_READER(IFILE);
    std::vector<std::string> pre_procced_lines;
    std::vector<std::string> deleted_white_lines;

// *******************************************pre procees*******************************************

    for (std::string str : code_lines){
        pre_procced_lines.push_back(FIL_STR(str));
    }
    for (std::string str : pre_procced_lines){
        if (IS_EMPTY(str)){
            deleted_white_lines.push_back(str);
        }
    }
    

// *******************************************lexing*******************************************



// *******************************************parsing*******************************************



// *******************************************create file*******************************************

    std::ofstream output(OFILE);

    if (output.is_open()){

        // std::vector<std::string> COFF {"64", "86"};


        // std::vector<int> sections(4);
        // for (std::string STR: deleted_white_lines){
        //     std::vector<std::string> sc = TOKENIZER(STR);
            
        //     if (sc[0] == "section"){
        //         if (sc[1] == ".data"){
        //             sections[0] = 1;
        //         }
        //         else if (sc[1] == ".bss"){
        //             sections[1] = 1;
        //         }
        //         else if (sc[1] == ".rdata"){
        //             sections[2] = 1;
        //         }
        //         else if (sc[1] == ".text"){
        //             sections[3] = 1;
        //         }
        //     }
        // }
        // int sec = 0;
        // for(int se : sections){sec += se;}
        // COFF.push_back("0" + std::to_string(sec));
        // COFF.push_back("00");
        // COFF.push_back("11");COFF.push_back("11");COFF.push_back("11");COFF.push_back("11");
        



        // for (std::string byte : COFF){
        //     writeHex(OFILE, byte);
        // }
        for (std::string line : deleted_white_lines){
            output << line << std::endl;
        }
        output.close();
        std::cout << "file created.";
    }
    else {
        std::cout << "error in create the file";
    }
}

void SHOWCM(std::string IFILE){

}

void DEBUG(std::string IFILE){
    
}