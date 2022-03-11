#include <string.h>

/*
. - Print value of current pointer
> - increase the pointer value by 1
< - decrease the pointer value by 1
+ - increase value of current position by next value (1-9)
- - increase value of current position by next value (1-9)
* - Print value of current pointer in ascii value
_ - Input a int and store the value in the current position
" - For single line comment ends if detects another quote
throws error if unexepected character is present or if Unxepected value to increase or decrease is given or too much incrementation or decrementation is done
default value of sizeof_data is 3000 you can increase it....
*/

int isNum(char t){
    char nums[] = "1234567890";
    for(int i = 0;i<10;i++){
        if(t == nums[i]){
            return 1; 
        }
    }
    return 0;
}

void compile(char * txt){
    //---Initialize maindata and some temporary variables for use---
    int sizeof_data = 3000;
    int *mainData = (int *) malloc(sizeof_data*sizeof(int));
    for(int i = 0;i<sizeof_data;i++){
        mainData[i] = 0;
    }
    //---By default the current pos is 0---
    int currentPos = 0;
    int currentLine = 0;
    //main loop

    while(*txt != '\0'){
        char temp[100];
        int temp_int = 0;
        // ---All commands---
        switch(*txt){
            // ---Incrementers---
            case '>':
                currentPos += 1;
                break;
            case '<':  
                currentPos -= 1;
                break;
            // ---Operators---
            case '+':
                
                if(isNum(*(txt+1)) == 0){
                    printf("\nError : Unxepected value to increase '%c'\n",*(txt+1));
                    exit(0);
                }
                txt++;
                temp_int = 0;
                while(isNum(*(txt)) == 1){
                    temp[temp_int] = *txt;
                    temp_int++;
                    txt++;
                }
                temp[temp_int] = '\0';
                mainData[currentPos] += atoi(temp);
                continue;
                break;
            case '-':
                if(isNum(*(txt+1)) == 0){
                    printf("\nError : Unxepected value to decrease '%c'\n",*(txt+1));
                    exit(0);
                }
                txt++;
                temp_int = 0;
                while(isNum(*(txt)) == 1){
                    temp[temp_int] = *txt;
                    temp_int++;
                    txt++;
                }
                temp[temp_int] = '\0';
                mainData[currentPos] -= atoi(temp);
                continue;
                break;
            // ---Built-in-Functions---
            case '.':
                printf("%d",mainData[currentPos]);
                break;
            case '*':
                printf("%c",mainData[currentPos]);
                break;
            case '_':
                {
                    int val;
                    scanf("%d",&val);
                    mainData[currentPos] = val;
                }
                break;
            //---Comments---
            // this one is a single line comment 
            case '"':
                txt++;
                while(*txt != '"'){
                    txt++;
                }
                // txt++;
                break;
            //---Some ignorations---
            case '\n':
                currentLine++;
                break;
            // ---By default give an error---
            default:
                printf("\nError : Unexepected Character '%c' at line %d\n",*txt,currentLine);
                exit(0);
                break;
        }
        //---Check if current pos is greater or less than limit then gives error---
        if(currentPos > sizeof_data){
            printf("\nError : Too much increamentation\n");
            exit(0);
        }
        if(currentPos < 0){
            printf("\nError : Too much decrementation\n");
            exit(0);
        }
        txt++;
    }
    free(mainData);
}