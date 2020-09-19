#ifndef DESCRIPTION_CONVERTER_TOOLS_PARAM
#define DESCRIPTION_CONVERTER_TOOLS_PARAM 1

#include "cursorTools.h"
#include "timeTools.h"
#include "hasherTools.h"

string descriptionConvert(string desc, int max_len) {
    string convertedDesc = "";

    int desc_len = desc.length();
    int counter = 0;
    for(int i = 0; i < desc_len; i++){
        if(counter == max_len){
            if(desc[i] == '\n'){
                convertedDesc += "\n";
                counter = 0;
            }
            else{
                convertedDesc += "\n";
                convertedDesc += desc[i];
                counter = 1;
            }
        }
        else if(desc[i] == '\n'){
            convertedDesc += "\n";
            counter = 0;
        }
        else{
            convertedDesc += desc[i];
            counter++;
        }
    }

    return convertedDesc;
}

#endif // DESCRIPTION_CONVERTER_TOOLS_PARAM
